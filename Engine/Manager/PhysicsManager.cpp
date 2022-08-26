#include "../include/Manager/PhysicsManager.hpp"
#include "../include/Physics/RigidBody.hpp"
#include "../include/Physics/Collider.hpp"
#include "../include/GameObject.hpp"

std::vector<RigidBody*> PhysicsManager::RigidBodys {};

void PhysicsManager::Update(){
    CollisionInfo Info {nullptr, Vector2{0,0}};
    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        for (size_t j = i + 1; j < RigidBodys.size(); j++)
        {   
            if(RigidBodys.at(i)->CheckCollision(RigidBodys.at(j), Info)){

                Info.other = RigidBodys.at(i)->owner;
                RigidBodys.at(j)->owner->onCollide(Info);

                // reverse result
                Info.deltaPos = -Info.deltaPos;

                Info.other = RigidBodys.at(j)->owner;
                RigidBodys.at(i)->owner->onCollide(Info);
        
            }
        }
    }
}

void PhysicsManager::Draw(){
    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        RigidBodys.at(i)->collider->Draw();
    }
}

void PhysicsManager::Add(RigidBody* rb){
    RigidBodys.push_back(rb);
}

void PhysicsManager::Remove(RigidBody* rb){
    for (size_t i = 0; i < RigidBodys.size(); i++)
    {
        if(RigidBodys.at(i) == rb){
            RigidBodys.erase(RigidBodys.begin()+i);
        }
    }
}

void PhysicsManager::Clear(){
   RigidBodys.clear();
}
