#include "include/GameObject.hpp"

GameObject::GameObject(int W, int H, std::string Tex, Vector2 Pos, int speed): Width {W}, Height {H}, Texture{Tex}, Position{Pos}, Speed{speed}
{
    rect.w = Width;
    rect.h = Height;
    rect.x = Position.X;
    rect.y = Position.Y;
}

void GameObject::Draw(){
    SDL_Rect size {static_cast<int>(Position.X),static_cast<int>(Position.Y),650,850};
    SDL_SetTextureColorMod(GFXManager::Get(Texture), 0,255,255); 
    SDL_Point Pivot {(int)(rect.w * 0.5f), (int)(rect.h * 0.5f)};
    //Render texture to screen
    SDL_RenderCopyEx( GFXManager::Renderer, GFXManager::Get(Texture), &size,  &rect, Position.X, &Pivot, SDL_FLIP_NONE );
}

void GameObject::Update(){
    Position.X += velocity.X * Speed;// * Clock::GetDeltaTime();
    Position.Y += velocity.Y * Speed;// * Clock::GetDeltaTime();
    
    //rect.x = Position.X;
    //rect.y = Position.Y;
    //rect.w = Width;
    //rect.h = Height;
}

void GameObject::Input(const Uint8 *keyboard_state_array){
    // Move centerpoint of rotation for one of the trees:
    if (keyboard_state_array[SDL_SCANCODE_UP] || keyboard_state_array[SDL_SCANCODE_W])
    {
        velocity.Y = -1;
    }
    else if (keyboard_state_array[SDL_SCANCODE_DOWN] || keyboard_state_array[SDL_SCANCODE_S])
    {
        velocity.Y = 1;
    }
    else{
        velocity.Y = 0;
    }

    if (keyboard_state_array[SDL_SCANCODE_RIGHT] || keyboard_state_array[SDL_SCANCODE_D])
    {
        velocity.X = 1;
    }
    else if(keyboard_state_array[SDL_SCANCODE_LEFT] || keyboard_state_array[SDL_SCANCODE_A])
    {
        velocity.X = -1;
    }
    else{
        velocity.X = 0;
    }
}

void GameObject::onCollide(ColliderInfo info){
    
}
