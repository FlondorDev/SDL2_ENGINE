#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <iostream>
#include <SDL.h>
#include "interfaces/Interfaces.hpp"
#include "Structs/Structs.hpp"
#include "Manager/Managers.hpp"
#include "Clock.hpp"

class Entity : public IController, public IDraw, public IUpdate
{
    private:
        SDL_Rect rect;
        Vector2 velocity;

    public:
        int Speed;
        Vector2 Position;
        std::string Texture;
        int Width;
        int Height;
        Entity(int, int, std::string, Vector2, int);
        void Draw() override;
        void Update() override;
        void Input(const Uint8 *keyboard_state_array) override;
};



#endif