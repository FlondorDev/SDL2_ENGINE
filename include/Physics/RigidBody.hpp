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

enum collisionMaskList {
    PLAYER = 1,
    PEPPER = 2,
    WALL = 4
};

class RigidBody
{
    
    private:
        Collider* collider;

    public:
        static float Gravity;
        static float MinGravity;
        static float MaxGravity;
        collisionMaskList collisionId;
        unsigned char collisionMask;
        GameObject* const owner;
        bool isGravityAffected;
        bool isGrounded;
        bool isActive;
        int Speed;
        Vector2* const Position;
        Vector2 Velocity;
        RigidBody(GameObject* owner, int speed = 0);
        ~RigidBody();
        void DestroyCollider();
        void Update();
        void Draw();
        void addCollisionMask(unsigned char mask);
        bool checkCollisionMask(unsigned char mask);
        bool CheckCollision(RigidBody* Other, CollisionInfo& Info);
        void CreateCircleCollider(int Radius, Vector2 Offset = {0,0});
        void CreateBoxCollider(int W, int H, Vector2 Offset = {0,0});
};

#endif