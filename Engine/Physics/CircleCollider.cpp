#include "../include/Physics/CircleCollider.hpp"
#include "../include/Physics/BoxCollider.hpp"

CircleCollider::CircleCollider(RigidBody* Owner, int R, Vector2 offset) : Collider(Owner,offset), r(R)
{
    
}

bool CircleCollider::CheckCollision(CircleCollider* Other){
    return (Other->r * Other->r) + (r * r) >= (Other->GetPosition() - GetPosition()).LenghtSquared();
}

bool CircleCollider::CheckCollision(BoxCollider* Other){
    return Other->CheckCollision(this);
}