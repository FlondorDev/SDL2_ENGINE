#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <iostream>
#include <SDL.h>
#include "GameObject.hpp"

class Player : public IController, public GameObject
{
    public:
        Player(std::string Tex, int W = 0, int H = 0, Vector2  = {0, 0}, int speed = 5);
        void Input(const Uint8 *keyboard_state_array) override;
        void onCollide(CollisionInfo info) override;
        void Update() override;
        void Jump();
};


#endif