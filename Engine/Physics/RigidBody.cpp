#include "../include/Physics/RigidBody.hpp"

RigidBody::RigidBody(GameObject* Owner) : owner(Owner), Position(&Owner->Position)
{

}

void RigidBody::OnCollide(ColliderInfo info){
    owner->onCollide(info);
}