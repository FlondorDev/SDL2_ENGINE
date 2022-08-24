#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <iostream>
#include <SDL.h>
#include "interfaces/Interfaces.hpp"
#include "Structs/Structs.hpp"
#include "Manager/Managers.hpp"
#include "Clock.hpp"

class GameObject : public IController, public IDraw, public IUpdate
{
    protected:
        SDL_Rect rect;
        Vector2 velocity;

    public:
        int Speed;
        Vector2 Position;
        std::string Texture;
        int Width;
        int Height;
        GameObject(int, int, std::string, Vector2, int);
        void Draw() override;
        void Update() override;
        void Input(const Uint8 *keyboard_state_array) override;
        void onCollide(ColliderInfo);
};



#endif