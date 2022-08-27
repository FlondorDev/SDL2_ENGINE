#ifndef _GFXMANAGER_H_
#define _GFXMANAGER_H_

#include "../interfaces/IDraw.hpp"
#include <iostream>
#include <map>
#include <SDL_image.h>

class GFXManager
{
    private:
        GFXManager();
        static std::map<std::string, SDL_Texture*> Surfaces;

    public:
        static SDL_Window* Window;
        static SDL_Renderer* Renderer;

        static void Add(std::string, std::string);
        static SDL_Texture* LoadImage(std::string);
        static SDL_Texture* Get(std::string);
        static void Remove(std::string, bool = true);
        static void Clear(bool = true);
        static void Init(std::string, int, int);
        static void Close();
};

#endif