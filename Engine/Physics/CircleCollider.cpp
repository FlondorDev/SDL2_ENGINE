#include "../include/Physics/CircleCollider.hpp"
#include "../include/Physics/BoxCollider.hpp"

CircleCollider::CircleCollider(RigidBody* Owner, int R, Vector2 offset) : Collider(Owner,offset), r(R)
{
    
}

bool CircleCollider::CheckCollision(CircleCollider* Other, CollisionInfo& Info){
    return (Other->r * Other->r) + (r * r) >= (Other->GetPosition() - GetPosition()).LenghtSquared();
}

bool CircleCollider::CheckCollision(BoxCollider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

bool CircleCollider::CheckCollision(Collider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

void CircleCollider::Draw(){
    SDL_SetRenderDrawColor(GFXManager::Renderer, 0,0,255,255);
    SDL_RenderDrawCircle(GFXManager::Renderer, GetPosition().X + r, GetPosition().Y + r, r);
}