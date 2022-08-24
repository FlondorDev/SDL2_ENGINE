#ifndef _CIRCLECOLLIDER_H_
#define _CIRCLECOLLIDER_H_
#include <iostream>
#include <SDL.h>
#include "../interfaces/Interfaces.hpp"
#include "../Structs/Structs.hpp"
#include "../Manager/Managers.hpp"
#include "Collider.hpp"

class BoxCollider;

class CircleCollider : public Collider
{
    friend class BoxCollider;

    private:
        int r;
    public:
        CircleCollider(RigidBody* owner, int R, Vector2 offset = {0,0});
        bool CheckCollision(CircleCollider*);
        bool CheckCollision(BoxCollider*);
};

#endif