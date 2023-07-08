#include "../../include/Physics/Collider.hpp"
#include "../../include/Physics/BoxCollider.hpp"
#include "../../include/Physics/CircleCollider.hpp"
#include "../../include/Physics/RigidBody.hpp"

Collider::Collider(RigidBody* Owner, Vector2 offset) : owner(Owner), Offset(offset)
{

}

void Collider::Draw(){

}

Vector2 Collider::GetPosition(){
    return (*owner->Position) + Offset;
}

bool Collider::CheckCollision(Collider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

bool Collider::CheckCollision(CircleCollider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

bool Collider::CheckCollision(BoxCollider* Other, CollisionInfo& Info){
    return Other->CheckCollision(this, Info);
}

int SDL_RenderDrawCircle(SDL_Renderer * renderer, int x, int y, int radius)
{
    int offsetx, offsety, d;
    int status;

    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}
