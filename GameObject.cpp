#include "include/GameObject.hpp"

GameObject::GameObject(std::string Tex, Vector2 Pos, int W, int H): Width {W}, Height {H}, Texture{Tex}, Position{Pos}, rb{this}
{
    if(W == 0 && H == 0){
        SDL_QueryTexture(GFXManager::Get(Tex), nullptr, nullptr, &Width, &Height);
    }

    rect.w = Width;
    rect.h = Height;
    rect.x = Position.X;
    rect.y = Position.Y;
    rb.CreateBoxCollider(Width, Height);
    rb.isActive = true;
    //rb.CreateCircleCollider(W * 0.5 + 25, Vector2{-25,-25});
}

void GameObject::Draw(){
    //SDL_FRect size {static_cast<int>(Position.X),static_cast<int>(Position.Y),650,850};
    //SDL_SetTextureColorMod(GFXManager::Get(Texture), 0,255,255); 
    //SDL_Point Pivot {(int)(rect.w * 0.5f), (int)(rect.h * 0.5f)};
    //Render texture to screen
    GFXManager::DrawTexture(Texture, &rect, Camera);
}

void GameObject::Update(){
    rb.Update();
    rect.x = Position.X;
    rect.y = Position.Y;
    //rect.w = Width;
    //rect.h = Height;
}

void GameObject::onCollide(CollisionInfo collisionInfo){
    //Position.X += collisionInfo.deltaPos.X;
    //Position.Y += collisionInfo.deltaPos.Y;
    //rect.x = Position.X;
    //rect.y = Position.Y;
}
