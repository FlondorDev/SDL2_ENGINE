#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_
#include <iostream>
#include <SDL.h>
#include "../interfaces/Interfaces.hpp"
#include "../Structs/Structs.hpp"
#include "../Manager/Managers.hpp"
#include "../Clock.hpp"
#include "../GameObject.hpp"

class RigidBody
{
    private:
        GameObject* const owner;

    public:
        Vector2* const Position;
        Vector2 Velocity;
        RigidBody(GameObject* owner);
        void Update();
        void OnCollide(ColliderInfo);
};



#endif