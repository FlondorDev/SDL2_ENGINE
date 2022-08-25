#ifndef _PHYSICSMANAGER_H_
#define _PHYSICSMANAGER_H_

#include <iostream>
#include <vector>

class RigidBody;

class PhysicsManager
{
    private:
        PhysicsManager();
        static std::vector<RigidBody*> RigidBodys;

    public:
        static void Add(RigidBody*);
        static void Update();
        static void Remove(RigidBody*);
        static void Clear();
};

#endif