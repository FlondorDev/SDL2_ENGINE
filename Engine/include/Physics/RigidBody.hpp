#ifndef _RIGIDBODY_H_
#define _RIGIDBODY_H_
#include <iostream>
#include <SDL.h>
#include "../interfaces/Interfaces.hpp"
#include "../Structs/Structs.hpp"
#include "../Manager/Managers.hpp"
#include "../Clock.hpp"

class Collider;
class GameObject;

class RigidBody
{
    friend class PhysicsManager;
    
    private:
        Collider* collider;
        GameObject* const owner;

    public:
        int Speed;
        Vector2* const Position;
        Vector2 Velocity;
        RigidBody(GameObject* owner, int speed = 0);
        ~RigidBody();
        void Update();
        bool CheckCollision(RigidBody* Other, CollisionInfo& Info);
        void CreateCircleCollider(int Radius, Vector2 Offset = {0,0});
        void CreateBoxCollider(int W, int H, Vector2 Offset = {0,0});
};

#endif