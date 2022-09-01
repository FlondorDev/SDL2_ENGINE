#include <SDL.h>
#include <SDL_image.h>
#include "Engine/include/Engine.hpp"
#include <iostream>

int main(int argc, char* args[])
{
    SDL_Event e{};
    bool quit = false;
    GFXManager::Init("Chironi");

    GFXManager::Add("Hello", "Assets/previewd.png");
    GFXManager::Add("Chiron", "Assets/Chironi.bmp");
    GFXManager::Add("Saul", "Assets/sas.png");
    GFXManager::Add("prev", "Assets/previewd.png");

    Camera camera;

    Player player {150,150,"Chiron",Vector2{30, 30},6};
    GameObject obj {1280,100,"Hello",Vector2{0, 620}};
    GameObject obj2 {150,150,"Hello",Vector2{0, 470}};
    GameObject obj3 {150,150,"Hello",Vector2{150, 320}};


    std::string Title;
    SDL_Rect viewPort = { GFXManager::LogicWidth - 64 - 128 , 64, 128, 128 };

    while (!quit) {
        //Clear screen
        SDL_RenderClear( GFXManager::Renderer );
        SDL_RenderSetViewport(GFXManager::Renderer, nullptr);

        Clock::StartTick();

        while(SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        ControllerManager::Input(SDL_GetKeyboardState(nullptr));

        UpdateManager::Update();
        
        PhysicsManager::Update();

        camera.Update();
        
        //SDL_RenderCopy(GFXManager::Renderer, GFXManager::Get("Saul"), &camera.CameraRender, nullptr);
        DrawManager::Draw();

        PhysicsManager::Draw();

        SDL_RenderSetViewport(GFXManager::Renderer, &viewPort);
        SDL_RenderCopy(GFXManager::Renderer, GFXManager::Get("prev"), nullptr, nullptr);
        
        //Update screen
        SDL_RenderPresent( GFXManager::Renderer );

        Clock::EndTick();
        Title = "Current FPS: " + std::to_string(Clock::GetFps()) + " Current DeltaTime: " + std::to_string(Clock::GetDeltaTime());
        SDL_SetWindowTitle(GFXManager::Window, Title.c_str());
 
    }

    ControllerManager::Clear();
    UpdateManager::Clear();
    PhysicsManager::Clear();
    DrawManager::Clear();
    GFXManager::Close();
    return 0;
}

int WinMain(int argc, char* args[]){
    return main(argc, args);
}

