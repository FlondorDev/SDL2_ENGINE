#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <iostream>
#include <SDL.h>
#include "interfaces/Interfaces.hpp"
#include "Structs/Structs.hpp"
#include "Manager/Managers.hpp"
#include "Clock.hpp"
#include "Physics/RigidBody.hpp"

class GameObject : public IDraw, public IUpdate
{
    protected:
        SDL_Rect rect;
        RigidBody rb;

    public:
        Vector2 Position;
        std::string Texture;
        int Width;
        int Height;
        GameObject(int W, int H, std::string Tex, Vector2 Pos);
        void Draw() override;
        void Update() override;
        virtual void onCollide(CollisionInfo);
};



#endif