#ifndef _GFXMANAGER_H_
#define _GFXMANAGER_H_

#include "../interfaces/IDraw.hpp"
#include <iostream>
#include <map>
#include <SDL_image.h>
#include "../Structs/Vector2.hpp"
#include "../Camera.hpp"

class GFXManager
{
    private:
        GFXManager();
        static std::map<std::string, SDL_Texture*> Surfaces;

    public:
        static int ScreenWidth;
        static int ScreenHeight;
        static int LogicWidth;
        static int LogicHeight;

        static SDL_Window* Window;
        static SDL_Renderer* Renderer;
        static Camera* MainCamera;

        static Vector2 GetPositionRelativeToCamera(Vector2 Position);
        static void DrawTexture(std::string Texture, SDL_FRect* RenderSquare, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_FPoint* center = nullptr, SDL_RendererFlip flipMode = SDL_FLIP_NONE);
        static void Add(std::string, std::string);
        static SDL_Texture* LoadImage(std::string);
        static SDL_Texture* Get(std::string);
        static void Remove(std::string, bool = true);
        static void Clear(bool = true);
        static void Init(std::string title);
        static void Close();
};

#endif