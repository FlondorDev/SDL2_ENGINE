#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <iostream>
#include <SDL.h>
#include "Physics/RigidBody.hpp"
#include "interfaces/Interfaces.hpp"
#include "Structs/Structs.hpp"
#include "Manager/Managers.hpp"
#include "Clock.hpp"


class GameObject : public IDraw, public IUpdate
{
    protected:
        SDL_FRect rect;
        
    public:
        RigidBody rb;
        Camera* Camera = nullptr;
        Vector2 Position;
        std::string Texture;
        bool repeatTexture;
        int Width;
        int Height;
        GameObject(std::string Tex, Vector2 Pos = {0,0}, int W = 0, int H = 0, bool repeatTex = true);
        void Draw(SDL_RendererFlip mode) override;
        void Update() override;
        virtual void onCollide(CollisionInfo);
};



#endif