#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <iostream>
#include <SDL.h>
#include "Physics/RigidBody.hpp"
#include "interfaces/Interfaces.hpp"
#include "Structs/Structs.hpp"
#include "Manager/Managers.hpp"
#include "Clock.hpp"


class GameObject : public IDraw, public IUpdate
{
    protected:
        SDL_FRect rect;
        RigidBody rb;
        
    public:
        Camera* Camera;
        Vector2 Position;
        std::string Texture;
        int Width;
        int Height;
        GameObject(std::string Tex, int W = 0, int H = 0, Vector2 Pos = {0,0});
        void Draw() override;
        void Update() override;
        virtual void onCollide(CollisionInfo);
};



#endif