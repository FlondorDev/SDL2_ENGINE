#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <SDL.h>
#include "GameObject.hpp"

class Player : public IController, public GameObject
{
    public:
        Player(int W, int H, std::string Tex, Vector2 Pos, int speed);
        void Input(const Uint8 *keyboard_state_array) override;
        void onCollide(CollisionInfo info) override;
        void Update() override;
        void Jump();
};


#endif