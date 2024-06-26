#include "../include/Physics/BoxCollider.hpp"
#include "../include/Physics/CircleCollider.hpp"
#include "../include/Physics/RigidBody.hpp"
#include "../include/GameObject.hpp"

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
    if(GetPosition().X - (w *0.5f) <= Other->GetPosition().X + (Other->w *0.5f) &&
           GetPosition().X + (w *0.5f) >= Other->GetPosition().X - (Other->w *0.5f) &&
           GetPosition().Y - (h *0.5f) <= Other->GetPosition().Y + (Other->h *0.5f) &&
           GetPosition().Y + (h *0.5f) >= Other->GetPosition().Y - (Other->h *0.5f))
    {
        SDL_SetRenderDrawColor(GFXManager::Renderer, 255,0,0,255);
        Info.deltaPos = (Vector2{Other->GetPosition().X, Other->GetPosition().Y} - Vector2{GetPosition().X , GetPosition().Y});

        Info.deltaPos.X = -(abs(Info.deltaPos.X) - ((w *0.5f) + (Other->w *0.5f)));
        Info.deltaPos.Y = -(abs(Info.deltaPos.Y) - ((h *0.5f) + (Other->h *0.5f)));

        if (Info.deltaPos.X < Info.deltaPos.Y)
        {
            // Horizontal Collision
            if (GetPosition().X < Other->GetPosition().X)
            {
                Info.collision |= CollisionType::LEFT;
                // Collision from Left (inverse horizontal delta)
                Info.deltaPos.X = -Info.deltaPos.X;
            }else{
                Info.collision |= CollisionType::RIGHT;
            }

            Info.deltaPos.Y = 0;
            owner->Velocity.X = 0.0f;
        }
        else
        {
            // Vertical Collision
            if (GetPosition().Y < Other->GetPosition().Y)
            {
                Info.collision |= CollisionType::TOP;
                // Collision from Top
                Info.deltaPos.Y = -Info.deltaPos.Y;
                owner->Velocity.Y = 0.0f;
                Other->owner->Velocity.Y = -Other->owner->Velocity.Y * 0.2f;
            }
            else
            {
                Info.collision |= CollisionType::BOTTOM;
                // Collision from Bottom
                Other->owner->Velocity.Y = 0.0f;
                owner->Velocity.Y = -owner->Velocity.Y * 0.2f;
            }

            Info.deltaPos.X = 0;
        }

        return true;
    }
    SDL_SetRenderDrawColor(GFXManager::Renderer, 0,255,0,255);
    return false;
}

Vector2 BoxCollider::GetPosition(){
    return (Vector2 {owner->Position->X + (w * 0.5f), owner->Position->Y + (h * 0.5f)} ) + Offset;
    //return Collider::GetPosition();
}

bool BoxCollider::CheckCollision(CircleCollider* Other, CollisionInfo& Info){
    float deltaX = Other->GetPosition().X - Max(GetPosition().X - (w*0.5f), Min(Other->GetPosition().X, GetPosition().X + (w*0.5f)));
    float deltaY = Other->GetPosition().Y - Max(GetPosition().Y - (h*0.5f), Min(Other->GetPosition().Y, GetPosition().Y + (h*0.5f)));

    if((deltaX * deltaX + deltaY * deltaY) < (Other->r * Other->r)){
        Vector2 dist {-deltaX, -deltaY};
        dist.Normalize();

        Info.deltaPos.X = -(abs(deltaX) - (abs(dist.X) * Other->r));
        Info.deltaPos.Y = -(abs(deltaY) - (abs(dist.Y) * Other->r));

        // Horizontal Collision
        if (GetPosition().X < Other->GetPosition().X)
        {
            Info.collision |= CollisionType::LEFT;
            // Collision from Left (inverse horizontal delta)
            Info.deltaPos.X = -Info.deltaPos.X;
        }else{
            Info.collision |= CollisionType::RIGHT;
        }

        // Vertical Collision
        if (GetPosition().Y < Other->GetPosition().Y)
        {
            Info.collision |= CollisionType::TOP;
            // Collision from Top
            Info.deltaPos.Y = -Info.deltaPos.Y;
        }else{
            Info.collision |= CollisionType::BOTTOM;
        }
    
        return true;
    }
    return false;
}

bool BoxCollider::CheckCollision(Collider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

void BoxCollider::Draw(){
    SDL_FRect draw {Collider::GetPosition().X,Collider::GetPosition().Y, static_cast<float>(w), static_cast<float>(h)};
    draw.x += (owner->owner->Camera != nullptr ? owner->owner->Camera->CameraRender.x : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.x : 0));
    draw.y += (owner->owner->Camera != nullptr ? owner->owner->Camera->CameraRender.y : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.y : 0));
   
    SDL_SetRenderDrawColor(GFXManager::Renderer, 255,0,0,255);
    SDL_RenderDrawRectF(GFXManager::Renderer, &draw);
    SDL_SetRenderDrawColor(GFXManager::Renderer, 0,0,0,255);
}
