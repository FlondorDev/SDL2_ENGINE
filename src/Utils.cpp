#include "../include/Utils.hpp"

Vector2 Utils::Lerp(Vector2 origin, Vector2 end, float delta)
{
    return (origin + ((end - origin) * delta));
}

void Utils::Lerp(SDL_Rect *origin, Vector2 end, float delta)
{
    Vector2 tmp = Lerp(SDL_Rect2Vector2(origin), end, delta);
    origin->x = tmp.X;
    origin->y = tmp.Y;
}

void Utils::Lerp(SDL_FRect *origin, Vector2 end, float delta)
{
    Vector2 tmp = Lerp(SDL_FRect2Vector2(origin), end, delta);
    origin->x = tmp.X;
    origin->y = tmp.Y;
}

Vector2 Utils::SDL_Rect2Vector2(SDL_Rect *src)
{
    return Vector2{src->x, src->y};
}

Vector2 Utils::SDL_FRect2Vector2(SDL_FRect *src)
{
    return Vector2{src->x, src->y};
}

SDL_Rect Utils::SDL_FRect2SDL_Rect(SDL_FRect *src)
{
    return SDL_Rect{static_cast<int>(src->h), static_cast<int>(src->w), static_cast<int>(src->x), static_cast<int>(src->y)};
}
