#ifndef _COLLIDER_H_
#define _COLLIDER_H_
#include <iostream>
#include <SDL.h>
#include "../interfaces/Interfaces.hpp"
#include "../Structs/Structs.hpp"
#include "../Manager/Managers.hpp"

class RigidBody;
class CircleCollider;
class BoxCollider;


class Collider
{
    protected:
        Collider(RigidBody* owner, Vector2 Offset);
    public:
        RigidBody* const owner;
        Vector2 Offset;
        virtual Vector2 GetPosition();
        virtual bool CheckCollision(Collider*, CollisionInfo& Info);
        virtual bool CheckCollision(CircleCollider*, CollisionInfo& Info);
        virtual bool CheckCollision(BoxCollider*, CollisionInfo& Info);
        virtual void Draw();
};

int SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius);    

#endif