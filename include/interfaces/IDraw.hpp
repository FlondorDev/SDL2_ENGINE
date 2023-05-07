#ifndef _IDRAW_H_
#define _IDRAW_H_
#include <SDL.h>

class IDraw
{
    protected:
        IDraw();
        ~IDraw();

    public:
        virtual void Draw(SDL_RendererFlip mode = SDL_FLIP_NONE) {}
};  

#endif