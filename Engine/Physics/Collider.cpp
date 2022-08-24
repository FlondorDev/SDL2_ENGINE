#include "../include/Physics/Collider.hpp"

Collider::Collider(RigidBody* Owner, Vector2 offset) : owner(Owner), Offset(offset)
{

}

void Collider::OnCollide(ColliderInfo Info){
    owner->OnCollide(Info);
}