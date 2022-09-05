#include "../include/Physics/CircleCollider.hpp"
#include "../include/Physics/BoxCollider.hpp"
#include "../include/Physics/RigidBody.hpp"
#include "../include/GameObject.hpp"

CircleCollider::CircleCollider(RigidBody* Owner, int R, Vector2 offset) : Collider(Owner,offset), r(R)
{
    
}

Vector2 CircleCollider::GetPosition(){
    return (Vector2 {owner->Position->X + (r), owner->Position->Y + (r)} ) + Offset;
}

bool CircleCollider::CheckCollision(CircleCollider* Other, CollisionInfo& Info){
    Vector2 dist = (Other->GetPosition() - GetPosition());
    if(((Other->r + r) * (Other->r + r)) >= dist.LenghtSquared()){
        
        Vector2 distNormalized = dist.Normalized();

        Info.deltaPos.X = -(abs(dist.X) - (abs(distNormalized.X) * (Other->r + r)));
        Info.deltaPos.Y = -(abs(dist.Y) - (abs(distNormalized.Y) * (Other->r + r)));

        // Horizontal Collision
        if (GetPosition().X < Other->GetPosition().X)
        {
            Info.collision |= CollisionType::LEFT;
            // Collision from Left (inverse horizontal delta)
            Info.deltaPos.X = -Info.deltaPos.X;
        }
        else
        {
            Info.collision |= CollisionType::BOTTOM;
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

bool CircleCollider::CheckCollision(BoxCollider* Other, CollisionInfo& Info){
    bool result = Other->CheckCollision(this, Info);
    if(result){
        Info.collision = ~Info.collision;
        Info.deltaPos = -Info.deltaPos;
    }
    return result;
}

bool CircleCollider::CheckCollision(Collider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

void CircleCollider::Draw(){
    SDL_SetRenderDrawColor(GFXManager::Renderer, 0,0,255,255);

    SDL_RenderDrawCircle(
        GFXManager::Renderer, 
        GetPosition().X + (owner->owner->Camera != nullptr ? owner->owner->Camera->CameraRender.x : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.x : 0)), 
        GetPosition().Y + (owner->owner->Camera != nullptr ? owner->owner->Camera->CameraRender.y : (CameraManager::MainCamera != nullptr ? CameraManager::MainCamera->CameraRender.y : 0)), 
        r
    );

    SDL_SetRenderDrawColor(GFXManager::Renderer, 0,0,0,255);
}