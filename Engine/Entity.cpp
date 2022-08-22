#include "include/Entity.hpp"

Entity::Entity(int W, int H, std::string Tex, Vector2 Pos, int speed): Width {W}, Height {H}, Texture{Tex}, Position{Pos}, Speed{speed}
{
    rect.w = Width;
    rect.h = Height;
    rect.x = Position.X;
    rect.y = Position.Y;
}

void Entity::Draw(){
    //Render texture to screen
    SDL_RenderCopy( GFXManager::Renderer, GFXManager::Get(Texture), NULL,  &rect );
}

void Entity::Update(){
    Position.X += velocity.X * Speed;// * Clock::GetDeltaTime();
    Position.Y += velocity.Y * Speed;// * Clock::GetDeltaTime();
    rect.x = Position.X;
    rect.y = Position.Y;
    //rect.w = Width;
    //rect.h = Height;
}

void Entity::Input(const Uint8 *keyboard_state_array){
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
