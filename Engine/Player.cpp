#include "include/Player.hpp"

Player::Player(int W, int H, std::string Tex, Vector2 Pos, int speed): GameObject{W,H,Tex,Pos,speed}{
    rb.CreateBoxCollider(W+2,H+2, Vector2{-1,-1});
}

void Player::Input(const Uint8 *keyboard_state_array){
    // Move centerpoint of rotation for one of the trees:
    if (keyboard_state_array[SDL_SCANCODE_UP] || keyboard_state_array[SDL_SCANCODE_W])
    {
        rb.Velocity.Y = -1;
    }
    else if (keyboard_state_array[SDL_SCANCODE_DOWN] || keyboard_state_array[SDL_SCANCODE_S])
    {
        rb.Velocity.Y = 1;
    }
    else{
        rb.Velocity.Y = 0;
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
    std::cout<<Position.X<<std::endl;
    if (collisionInfo.deltaPos.X > collisionInfo.deltaPos.Y)
    {
        // Horizontal Collision
        if (Position.X > collisionInfo.other->Position.X)
        {
            // Collision from Left (inverse horizontal delta)
            collisionInfo.deltaPos.X = -collisionInfo.deltaPos.X;
        }

        Position.X += collisionInfo.deltaPos.X;
        rb.Velocity.X = 0.0f;
    }
    else
    {
        // Vertical Collision
        if (Position.Y > collisionInfo.other->Position.Y)
        {
            // Collision from Top
            collisionInfo.deltaPos.Y = -collisionInfo.deltaPos.Y;
            rb.Velocity.Y = 0.0f;
        }
        else
        {
            // Collision from Bottom
            rb.Velocity.Y = -rb.Velocity.Y * 0.8f;
        }

        Position.Y += collisionInfo.deltaPos.Y;
    }

    rect.x = Position.X;
    rect.y = Position.Y;
}
