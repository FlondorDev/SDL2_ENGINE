#include "../include/Physics/BoxCollider.hpp"
#include "../include/Physics/CircleCollider.hpp"

float Abs(float a){
    if( a < 0){
        return -a;
    }
    return a;
}

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

bool BoxCollider::CheckCollision(BoxCollider* Other, CollisionInfo& Info){

    if(GetPosition().X < Other->GetPosition().X + Other->w &&
           GetPosition().X + w > Other->GetPosition().X &&
           GetPosition().Y < Other->GetPosition().Y + Other->h &&
           GetPosition().Y + h > Other->GetPosition().Y)
    {
        Info.deltaPos = (Vector2{Other->GetPosition().X + (w *0.5f), Other->GetPosition().Y + (Other->h *0.5f)} - Vector2{GetPosition().X + (Other->w *0.5f), GetPosition().Y + (h *0.5f)});
       
        Info.deltaPos.X = (abs(Info.deltaPos.X) - ((w *0.5f) + (Other->w *0.5f)));
        Info.deltaPos.Y = (abs(Info.deltaPos.Y) - ((h *0.5f) + (Other->h *0.5f)));

        return true;
    }
    return false;
}

bool BoxCollider::CheckCollision(CircleCollider* Other, CollisionInfo& Info){
    float deltaX = Other->GetPosition().X - Max(GetPosition().X - (w*0.5f), Min(Other->GetPosition().X, GetPosition().X + (w*0.5f)));
    float deltaY = Other->GetPosition().Y - Max(GetPosition().Y - (h*0.5f), Min(Other->GetPosition().Y, GetPosition().Y + (h*0.5f)));

    if((deltaX * deltaX + deltaY * deltaY) < (Other->r * Other->r)){
        Info.deltaPos.X = deltaX;
        Info.deltaPos.Y = deltaY;
        return true;
    }

    return false;
}

bool BoxCollider::CheckCollision(Collider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

void BoxCollider::Draw(){
    SDL_Rect draw {(int)GetPosition().X,(int)GetPosition().Y, w,h};
    SDL_SetRenderDrawColor(GFXManager::Renderer, 255,0,0,255);
    SDL_RenderDrawRect(GFXManager::Renderer, &draw);
    SDL_SetRenderDrawColor(GFXManager::Renderer, 0,0,0,255);
}
