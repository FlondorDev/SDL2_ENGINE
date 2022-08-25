#ifndef _COLLISIONINFO_H_
#define _COLLISIONINFO_H_

#include "Vector2.hpp"

class GameObject;

struct CollisionInfo
{
    GameObject* other;
    Vector2 deltaPos;

    CollisionInfo(GameObject* O, Vector2 DP): other{O}, deltaPos{DP}{
        
    }
};
#endif
