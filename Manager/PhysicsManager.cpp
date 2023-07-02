#include "../include/Manager/PhysicsManager.hpp"
#include "../include/Physics/RigidBody.hpp"
#include "../include/Physics/Collider.hpp"
#include "../include/GameObject.hpp"

std::vector<RigidBody *> PhysicsManager::RigidBodys{};

Uint8 reverseCollisionType(Uint8 collision)
{
    Uint8 c = 0;

    if (collision & CollisionType::TOP)
        c |= CollisionType::BOTTOM;
    else if (collision & CollisionType::BOTTOM)
        c |= CollisionType::TOP;

    if (collision & CollisionType::LEFT)
        c |= CollisionType::RIGHT;
    else if (collision & CollisionType::RIGHT)
        c |= CollisionType::LEFT;

    return c;
}

void PhysicsManager::Update()
{
    CollisionInfo Info{nullptr, Vector2{0, 0}};

    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        if (!RigidBodys.at(i)->isActive)
            continue;
        RigidBodys.at(i)->isGrounded = false;
    }

    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        if (!RigidBodys.at(i)->isActive)
            continue;
        for (size_t j = i + 1; j < RigidBodys.size(); j++)
        {
            if (!RigidBodys.at(j)->isActive)
                continue;
            Info.collision = 0;
            if (RigidBodys.at(j)->CheckCollision(RigidBodys.at(i), Info))
            {
                if (RigidBodys.at(i)->checkCollisionMask(RigidBodys.at(j)->collisionId))
                {
                    Info.other = RigidBodys.at(j)->owner;
                    RigidBodys.at(i)->isGrounded = RigidBodys.at(i)->isGrounded ? true : Info.collision & CollisionType::TOP;
                    RigidBodys.at(i)->owner->onCollide(Info);
                }

                if (RigidBodys.at(j)->checkCollisionMask(RigidBodys.at(i)->collisionId))
                {
                    // reverse result
                    Info.collision = reverseCollisionType(Info.collision);
                    Info.deltaPos = -Info.deltaPos;

                    Info.other = RigidBodys.at(i)->owner;
                    RigidBodys.at(j)->isGrounded = RigidBodys.at(j)->isGrounded ? true : Info.collision & CollisionType::TOP;
                    RigidBodys.at(j)->owner->onCollide(Info);
                }
            }
        }
    }
}

void PhysicsManager::Draw()
{
    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        RigidBodys.at(i)->Draw();
    }
}

void PhysicsManager::Add(RigidBody *rb)
{
    RigidBodys.push_back(rb);
}

void PhysicsManager::Remove(RigidBody *rb)
{
    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        if (RigidBodys.at(i) == rb)
        {
            RigidBodys.erase(RigidBodys.begin() + i);
        }
    }
}

void PhysicsManager::Clear()
{
    RigidBodys.clear();
}
