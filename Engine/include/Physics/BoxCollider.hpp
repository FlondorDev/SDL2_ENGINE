#ifndef _BOXCOLLIDER_H_
#define _BOXCOLLIDER_H_
#include <iostream>
#include <SDL.h>
#include "../interfaces/Interfaces.hpp"
#include "../Structs/Structs.hpp"
#include "../Manager/Managers.hpp"
#include "Collider.hpp"

class CircleCollider;

class BoxCollider : public Collider
{
    private:
        int w, h;
    public:
        BoxCollider(RigidBody* owner, int w, int h, Vector2 offset = {0,0});
        bool CheckCollision(Collider*, CollisionInfo& Info) override;
        bool CheckCollision(CircleCollider*, CollisionInfo& Info) override;
        bool CheckCollision(BoxCollider*, CollisionInfo& Info) override;
        void Draw() override;
};



#endif