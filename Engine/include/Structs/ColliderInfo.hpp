#ifndef _COLLIDERINFO_H_
#define _COLLIDERINFO_H_

#include "Vector2.hpp"

class GameObject;

struct ColliderInfo
{
    GameObject* other;
    Vector2 deltaPos;
};
#endif
