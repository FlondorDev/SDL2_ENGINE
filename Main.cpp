#include <SDL.h>
#include <SDL_image.h>
#include "Engine/include/Engine.hpp"
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* args[])
{
    SDL_Event e{};
    bool quit = false;
    GFXManager::Init("Chironi",SCREEN_WIDTH,SCREEN_HEIGHT);

    GFXManager::Add("Hello", "Assets/preview.png");
    GFXManager::Add("Chiron", "Assets/Chironi.bmp");

    Entity player {150,150,"Chiron",Vector2{30,30},8};
    std::string Title;

    while (!quit) {
        Clock::StartTick();

        while(SDL_PollEvent(&e) != 0){
             if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        ControllerManager::Input(SDL_GetKeyboardState(NULL));

        UpdateManager::Update();

        //Clear screen
        SDL_RenderClear( GFXManager::Renderer );
        SDL_RenderCopy(GFXManager::Renderer, GFXManager::Get("Hello"), NULL, NULL);
        DrawManager::Draw();

        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_SetRenderDrawColor( GFXManager::Renderer, 255, 0, 0, 255 );        
        SDL_RenderFillRect( GFXManager::Renderer, &fillRect );

        SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
        SDL_SetRenderDrawColor( GFXManager::Renderer, 0, 255, 0, 255 );        
        SDL_RenderDrawRect( GFXManager::Renderer, &outlineRect );

        SDL_SetRenderDrawColor( GFXManager::Renderer, 0, 0, 255, 255 );        
        SDL_RenderDrawLine( GFXManager::Renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
        SDL_RenderDrawLine( GFXManager::Renderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT );
        SDL_RenderDrawLine( GFXManager::Renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );

        SDL_SetRenderDrawColor( GFXManager::Renderer, 0xFF, 0xFF, 0x00, 0xFF );
        for( int i = 0; i < SCREEN_HEIGHT; i += 4 )
        {
            SDL_RenderDrawPoint( GFXManager::Renderer, SCREEN_WIDTH / 2, i );
        }

        //Update screen
        SDL_RenderPresent( GFXManager::Renderer );

        Clock::EndTick();
        Title = "Current FPS: " + std::to_string(Clock::GetFps()) + " Current DeltaTime: " + std::to_string(Clock::GetDeltaTime());
        SDL_SetWindowTitle(GFXManager::Window, Title.c_str());
 
    }

    GFXManager::Close();
    return 0;
}
