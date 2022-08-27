#ifndef _COLLISIONINFO_H_
#define _COLLISIONINFO_H_

#include "Vector2.hpp"

class GameObject;

enum CollisionType{
    TOP = 1,
    BOTTOM = 2,
    LEFT = 4,
    RIGHT = 8
};

struct CollisionInfo
{
    GameObject* other;
    Vector2 deltaPos;
    Uint8 collision;

    CollisionInfo(GameObject* O, Vector2 DP): other{O}, deltaPos{DP}, collision{0}{
        
    }
};
#endif
