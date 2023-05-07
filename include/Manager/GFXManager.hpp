#ifndef _GFXMANAGER_H_
#define _GFXMANAGER_H_

#include "../interfaces/IDraw.hpp"
#include <iostream>
#include <map>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "../Structs/Vector2.hpp"
#include "../Camera.hpp"

class GFXManager
{
private:
    GFXManager();
    static std::map<std::string, SDL_Texture *> Surfaces;

public:
    static int ScreenWidth;
    static int ScreenHeight;
    static int LogicWidth;
    static int LogicHeight;

    static SDL_Window *Window;
    static SDL_Renderer *Renderer;
    static TTF_Font *DefaultFont;

    static Vector2 GetPositionRelativeToCamera(Vector2 Position, Camera *Camera = nullptr);
    static void DrawTexture(std::string Texture, SDL_FRect *RenderSquare, Camera *Camera = nullptr, SDL_Rect *clip = nullptr, SDL_RendererFlip flipMode = SDL_FLIP_NONE, double angle = 0.0, SDL_FPoint *center = nullptr);
    static void Add(std::string, std::string Path);
    static void Add(std::string key, SDL_Texture *Texture);
    static SDL_Texture *LoadImage(std::string Path);
    static SDL_Texture *CreateTextImage(std::string Text, SDL_Color Color = {.r = 0, .g = 0, .b = 0, .a = 255}, TTF_Font *Font = nullptr);
    static SDL_Texture *Get(std::string);
    static void Remove(std::string, bool = true);
    static void Clear(bool = true);
    static void Init(std::string title);
    static void Close();
};

#endif