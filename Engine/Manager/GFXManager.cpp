#include "../include/Manager/GFXManager.hpp"

std::map<std::string, SDL_Texture*> GFXManager::Surfaces {};

SDL_Window* GFXManager::Window {nullptr};

SDL_Renderer* GFXManager::Renderer {nullptr};

void GFXManager::Add(std::string key, std::string path){
    Surfaces.insert(std::pair<std::string,SDL_Texture*>(key,GFXManager::LoadImage(path)));
}

SDL_Texture* GFXManager::LoadImage(std::string path){
    SDL_Surface* tmp = IMG_Load(path.c_str());
    if (tmp == nullptr) {
        printf("SDL Error: %s\n", SDL_GetError());
        return nullptr;
    }
    SDL_Texture* tmpOpt = SDL_CreateTextureFromSurface(GFXManager::Renderer, tmp);

    SDL_FreeSurface(tmp);
    return tmpOpt;
}

SDL_Texture* GFXManager::Get(std::string key){
    return Surfaces.at(key);
}

void GFXManager::Remove(std::string key, bool free){
    if(free){
        SDL_DestroyTexture(Surfaces.at(key));
    }
    Surfaces.erase(key);
}

void GFXManager::Clear(bool free){
    if(free){
        std::map<std::string, SDL_Texture*>::iterator itr;

        for (itr = Surfaces.begin(); itr != Surfaces.end(); ++itr) {
            SDL_DestroyTexture(itr->second);
        }
    }
    Surfaces.clear();
}

void GFXManager::Init(std::string title, int W, int H)
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL_Error: %s\n", SDL_GetError());

    }
    else
    {
        Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, SDL_WINDOW_SHOWN);
        //Create window
        if (Window == NULL)
        {
            printf("SDL_Error: %s\n", SDL_GetError());
        }

        //Create renderer for window
        Renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED );
        if( Renderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor( Renderer, 0xFF, 0xFF, 0xFF, 0xFF );

            if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ){
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
            }
        }

    }
}

void GFXManager::Close()
{
    std::map<std::string, SDL_Texture*>::iterator itr;

    for (itr = Surfaces.begin(); itr != Surfaces.end(); ++itr) {
        SDL_DestroyTexture(itr->second);
    }

    SDL_DestroyWindow(Window);

    SDL_Quit();
}