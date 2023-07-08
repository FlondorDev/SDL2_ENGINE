#ifndef _UTILS_H_
#define _UTILS_H_

#include <SDL.h>
#include <iostream>
#include "./Structs/Vector2.hpp"

class Utils
{
    private:
        Utils();

    public:
        static Vector2 SDL_Rect2Vector2(SDL_Rect*);
        static Vector2 SDL_FRect2Vector2(SDL_FRect*);
        static SDL_Rect SDL_FRect2SDL_Rect(SDL_FRect *src);
        static Vector2 Lerp(Vector2 origin, Vector2 end, float delta);
        static void Lerp(SDL_Rect* origin, Vector2 end, float delta);
        static void Lerp(SDL_FRect* origin, Vector2 end, float delta);
};

#endif