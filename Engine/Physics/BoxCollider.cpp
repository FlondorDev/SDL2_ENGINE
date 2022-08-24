#include "../include/Physics/BoxCollider.hpp"
#include "../include/Physics/CircleCollider.hpp"

float Max(float A, float B){
    if(A>B) return A;
    else return B;
}

float Min(float A, float B){
    if(A<B) return A;
    else return B;
}

BoxCollider::BoxCollider(RigidBody* Owner, int W, int H, Vector2 offset) : Collider(Owner,offset), w(W), h(H)
{
    
}

bool BoxCollider::CheckCollision(BoxCollider* Other){
    return GetPosition().X <= Other->GetPosition().X + Other->w &&
           GetPosition().X + w >= Other->GetPosition().X &&
           GetPosition().Y <= Other->GetPosition().Y + Other->h &&
           GetPosition().Y + h >= Other->GetPosition().Y;
}

bool BoxCollider::CheckCollision(CircleCollider* Other){
    float deltaX = Other->GetPosition().X - Max(GetPosition().X - (w*0.5f), Min(Other->GetPosition().X, GetPosition().X + (w*0.5f)));
    float deltaY = Other->GetPosition().Y - Max(GetPosition().Y - (h*0.5f), Min(Other->GetPosition().Y, GetPosition().Y + (h*0.5f)));

    return (deltaX * deltaX + deltaY * deltaY) < (Other->r * Other->r);
}


