#include "include/Player.hpp"

Player::Player(std::string Tex, Vector2 Pos, int speed, int W, int H): GameObject{Tex, Pos, W, H}, jumps{2}, jumped{false}{
    rb.Speed = speed;
    rb.CreateBoxCollider(Width,Height);
    rb.isActive = true;
    rb.isGravityAffected = true;
    if(CameraManager::MainCamera != nullptr){
        CameraManager::MainCamera->SetTarget(this);
    }
    //rb.CreateCircleCollider(W * 0.5 + 25, Vector2{-25,-25});
}

void Player::Update(){
    rb.Update();
    rect.x = Position.X;
    rect.y = Position.Y;
}

void Player::Jump(){
    if(jumps > 0){
        jumps--;
        rb.Velocity.Y = RigidBody::MinGravity;
    }
}

void Player::Input(const Uint8 *keyboard_state_array){
    if(rb.isGrounded) jumps = 2;
    if(keyboard_state_array[SDL_SCANCODE_SPACE]){
        if(!jumped)
        {
            jumped = true;
            Jump();

        }
    }    
    else
    {
        jumped = false;
    }


    if (keyboard_state_array[SDL_SCANCODE_RIGHT] || keyboard_state_array[SDL_SCANCODE_D])
    {
        rb.Velocity.X = 1;
    }
    else if(keyboard_state_array[SDL_SCANCODE_LEFT] || keyboard_state_array[SDL_SCANCODE_A])
    {
        rb.Velocity.X = -1;
    }
    else{
        rb.Velocity.X = 0;
    }

    if (keyboard_state_array[SDL_SCANCODE_Q])
    {
        rb.Speed = 6;
    }
    else if(keyboard_state_array[SDL_SCANCODE_E])
    {
        rb.Speed = 12;
    }
}

void Player::onCollide(CollisionInfo collisionInfo){
    Position.X += collisionInfo.deltaPos.X;
    Position.Y += collisionInfo.deltaPos.Y;
    rect.x = Position.X;
    rect.y = Position.Y;
}
