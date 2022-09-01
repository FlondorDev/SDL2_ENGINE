#include "include/Player.hpp"

Player::Player(int W, int H, std::string Tex, Vector2 Pos, int speed): GameObject{W,H,Tex,Pos}{
    rb.Speed = speed;
    rb.CreateBoxCollider(W,H);
    rb.isActive = true;
    rb.isGravityAffected = true;
    if(GFXManager::MainCamera != nullptr)
        GFXManager::MainCamera->Target = this;
    //rb.CreateCircleCollider(W * 0.5 + 25, Vector2{-25,-25});
}

void Player::Update(){
    std::cout<<rb.isGrounded<<std::endl;
    rb.Update();
    rect.x = Position.X;
    rect.y = Position.Y;
}

void Player::Jump(){
    if(rb.isGrounded){
        rb.Velocity.Y += -30;
    }
}

void Player::Input(const Uint8 *keyboard_state_array){
    // Move centerpoint of rotation for one of the trees:
    if (keyboard_state_array[SDL_SCANCODE_SPACE])
    {
        Jump();
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
}

void Player::onCollide(CollisionInfo collisionInfo){
    Position.X += collisionInfo.deltaPos.X;
    Position.Y += collisionInfo.deltaPos.Y;
    rect.x = Position.X;
    rect.y = Position.Y;
}
