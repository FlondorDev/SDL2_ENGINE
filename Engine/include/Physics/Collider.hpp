#ifndef _COLLIDER_H_
#define _COLLIDER_H_
#include <iostream>
#include <SDL.h>
#include "../interfaces/Interfaces.hpp"
#include "../Structs/Structs.hpp"
#include "../Manager/Managers.hpp"
#include "RigidBody.hpp"


class Collider
{
    protected:
        RigidBody* const owner;
        Collider(RigidBody* owner, Vector2 Offset);
    public:
        Vector2 Offset;
        virtual inline Vector2 GetPosition();
        virtual inline bool CheckCollision(Collider*);
        virtual void OnCollide(ColliderInfo);
};

bool Collider::CheckCollision(Collider* Other){
    return Other->CheckCollision(this);
}

Vector2 Collider::GetPosition(){
    return (*owner->Position) + Offset;
}

#endif