#include "../include/Physics/RigidBody.hpp"
#include "../include/Physics/BoxCollider.hpp"
#include "../include/Physics/CircleCollider.hpp"
#include "../include/GameObject.hpp"

RigidBody::RigidBody(GameObject* Owner, int speed) : owner{Owner}, Position{&Owner->Position}, collider{nullptr}, Speed{speed}
{
    PhysicsManager::Add(this);
}

RigidBody::~RigidBody() {
    if(collider != nullptr){
        delete collider;
    }
}

void RigidBody::Update(){
    (*Position).X += Velocity.X * Speed;// * Clock::GetDeltaTime();
    (*Position).Y += Velocity.Y * Speed;// * Clock::GetDeltaTime();
}

bool RigidBody::CheckCollision(RigidBody* Other, CollisionInfo& Info){
    return collider->CheckCollision(Other->collider, Info);
}

void RigidBody::CreateCircleCollider(int Radius, Vector2 Offset){
    if(collider != nullptr) delete collider;
    collider = new CircleCollider{this,Radius,Offset};
}

void RigidBody::CreateBoxCollider(int W, int H, Vector2 Offset){
    if(collider != nullptr) delete collider;
    collider = new BoxCollider{this,W,H,Offset};
}