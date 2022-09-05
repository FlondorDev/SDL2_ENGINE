#include "../include/Physics/RigidBody.hpp"
#include "../include/Physics/BoxCollider.hpp"
#include "../include/Physics/CircleCollider.hpp"
#include "../include/GameObject.hpp"

float RigidBody::Gravity = 1.f;
float RigidBody::MinGravity = -16.f;
float RigidBody::MaxGravity = 8.f;

RigidBody::RigidBody(GameObject* Owner, int speed) : owner{Owner}, Position{&Owner->Position}, collider{nullptr}, Speed{speed}, isActive{false}, isGravityAffected{false}, isGrounded{false}
{
    PhysicsManager::Add(this);
}

RigidBody::~RigidBody() {
    DestroyCollider();
}

void RigidBody::Update(){
    if(isActive){
        if(isGravityAffected && !isGrounded){
            Velocity.Y += Gravity * Clock::GetDeltaTime();
            SDL_clamp(Velocity.Y, MinGravity, MaxGravity);
        }

        (*Position).X += (Velocity.X * Speed) * Clock::GetDeltaTime();
        (*Position).Y += (Velocity.Y);
    }
}    

void RigidBody::Draw(){
    if(collider != nullptr && isActive){
        collider->Draw();
    }
}

bool RigidBody::CheckCollision(RigidBody* Other, CollisionInfo& Info){
    if(collider == nullptr || Other->collider == nullptr) return false;
    return collider->CheckCollision(Other->collider, Info);
}

void RigidBody::CreateCircleCollider(int Radius, Vector2 Offset){
    if(collider != nullptr) delete collider;
    collider = new CircleCollider{this,Radius,Offset};
}

void RigidBody::CreateBoxCollider(int W, int H, Vector2 Offset){
    if(collider != nullptr) delete collider;
    collider = new BoxCollider{this, W, H, Offset};
}

void RigidBody::DestroyCollider(){
    if(collider != nullptr){
        delete collider;
        collider = nullptr;
    }
}