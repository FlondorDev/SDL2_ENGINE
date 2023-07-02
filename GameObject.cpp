#include "include/GameObject.hpp"

GameObject::GameObject(std::string Tex, Vector2 Pos, int W, int H, bool repeatTex) : Width{W}, Height{H}, Texture{Tex}, Position{Pos}, rb{this}, repeatTexture{repeatTex}
{
    if (W == 0 && H == 0)
    {
        SDL_QueryTexture(GFXManager::Get(Tex), nullptr, nullptr, &Width, &Height);
    }

    rb.collisionId = collisionMaskList::WALL;
    rect.w = Width;
    rect.h = Height;
    rect.x = Position.X;
    rect.y = Position.Y;
    rb.CreateBoxCollider(Width, Height);
    rb.isActive = true;
    // rb.CreateCircleCollider(W * 0.5 + 25, Vector2{-25,-25});
}

void GameObject::Draw(SDL_RendererFlip mode)
{

    // SDL_SetTextureColorMod(GFXManager::Get(Texture), 0,255,255);
    // SDL_Point Pivot {(int)(rect.w * 0.5f), (int)(rect.h * 0.5f)};
    // Render texture to screen
    if (repeatTexture)
    {
        int texH, texW;
        SDL_QueryTexture(GFXManager::Get(Texture), nullptr, nullptr, &texW, &texH);

        for (int h = Height, hi = 0; h > 0; h -= texH, hi++)
        {
            for (int w = Width, wi = 0; w > 0; w -= texW, wi++)
            {
                SDL_Rect size{0, 0, w >= texW ? texW : w, h >= texH ? texH : h};
                SDL_FRect rec{Position.X + (wi * texW), Position.Y + (hi * texH), static_cast<float>(size.w), static_cast<float>(size.h)};
                GFXManager::DrawTexture(Texture, &rec, Camera, &size, mode);
            }
        }
    }
    else
    {
        GFXManager::DrawTexture(Texture, &rect, Camera, nullptr, mode);
    }
}

void GameObject::Update()
{
    rb.Update();
    rect.x = Position.X;
    rect.y = Position.Y;
    // rect.w = Width;
    // rect.h = Height;
}

void GameObject::onCollide(CollisionInfo collisionInfo)
{
    // Position.X += collisionInfo.deltaPos.X;
    // Position.Y += collisionInfo.deltaPos.Y;
    // rect.x = Position.X;
    // rect.y = Position.Y;
}
