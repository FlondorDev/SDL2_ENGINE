#include "../include/Manager/GFXManager.hpp"
#include "../include/Manager/CameraManager.hpp"

std::map<std::string, SDL_Texture *> GFXManager::Surfaces{};

SDL_Window *GFXManager::Window{nullptr};

SDL_Renderer *GFXManager::Renderer{nullptr};

TTF_Font *GFXManager::DefaultFont{nullptr};

int GFXManager::ScreenWidth = 1280;
int GFXManager::ScreenHeight = 720;

int GFXManager::LogicWidth = 1280;
int GFXManager::LogicHeight = 720;

void GFXManager::Add(std::string key, std::string path)
{
    Surfaces.insert(std::pair<std::string, SDL_Texture *>(key, GFXManager::LoadImage(path)));
}

void GFXManager::Add(std::string key, SDL_Texture *Texture)
{
    Surfaces.insert(std::pair<std::string, SDL_Texture *>(key, Texture));
}

SDL_Texture *GFXManager::LoadImage(std::string path)
{
    SDL_Surface *tmp = IMG_Load(path.c_str());
    if (tmp == nullptr)
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return nullptr;
    }
    // SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format,255,255,255));
    SDL_Texture *tmpOpt = SDL_CreateTextureFromSurface(GFXManager::Renderer, tmp);

    SDL_FreeSurface(tmp);
    return tmpOpt;
}

SDL_Texture *GFXManager::CreateTextImage(std::string Text, SDL_Color Color, TTF_Font *Font)
{
    SDL_Surface *tmp = TTF_RenderText_Solid(Font != nullptr ? Font : DefaultFont, Text.c_str(), Color);
    if (tmp == nullptr)
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return nullptr;
    }
    // SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format,255,255,255));
    SDL_Texture *tmpOpt = SDL_CreateTextureFromSurface(GFXManager::Renderer, tmp);

    SDL_FreeSurface(tmp);
    return tmpOpt;
}

SDL_Texture *GFXManager::Get(std::string key)
{
    return Surfaces.at(key);
}

Vector2 GFXManager::GetPositionRelativeToCamera(Vector2 Position, Camera *Camera)
{
    Position.X -= (Camera != nullptr ? Camera->CameraRender.x : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.x : 0));
    Position.Y -= (Camera != nullptr ? Camera->CameraRender.y : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.y : 0));
    return Position;
}

void GFXManager::DrawTexture(std::string Texture, SDL_FRect *RenderSquare, Camera *Camera, SDL_Rect *clip, SDL_RendererFlip flipMode, double angle, SDL_FPoint *center)
{
    SDL_FRect RS {*RenderSquare};
    RS.x += (Camera != nullptr ? Camera->CameraRender.x : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.x : 0));
    RS.y += (Camera != nullptr ? Camera->CameraRender.y : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.y : 0));

    SDL_RenderCopyExF(GFXManager::Renderer, GFXManager::Get(Texture), clip, &RS, angle, center, flipMode);
}

void GFXManager::Remove(std::string key, bool free)
{
    if (free)
    {
        SDL_DestroyTexture(Surfaces.at(key));
    }
    Surfaces.erase(key);
}

void GFXManager::Clear(bool free)
{
    if (free)
    {
        std::map<std::string, SDL_Texture *>::iterator itr;

        for (itr = Surfaces.begin(); itr != Surfaces.end(); ++itr)
        {
            SDL_DestroyTexture(itr->second);
        }
    }
    Surfaces.clear();
}

void GFXManager::Init(std::string title)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
        // Create window
        if (Window == nullptr)
        {
            printf("SDL_Error: %s\n", SDL_GetError());
        }

        // Create renderer for window
        Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (Renderer == nullptr)
        {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            SDL_RenderSetLogicalSize(Renderer, LogicWidth, LogicHeight);
            // SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"),

            // SDL_ShowCursor(SDL_DISABLE);
            // Initialize renderer color
            SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);

            if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
            {
                printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            }

            // Initialize SDL_ttf
            if (TTF_Init() == -1)
            {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            }
        }
    }
}

void GFXManager::Close()
{

    std::map<std::string, SDL_Texture *>::iterator itr;

    for (itr = Surfaces.begin(); itr != Surfaces.end(); ++itr)
    {
        SDL_DestroyTexture(itr->second);
    }

    SDL_DestroyWindow(Window);
    if (DefaultFont != nullptr)
        TTF_CloseFont(DefaultFont);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}