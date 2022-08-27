#ifndef _UPDATEMANAGER_H_
#define _UPDATEMANAGER_H_

#include "../interfaces/IUpdate.hpp"
#include <iostream>
#include <vector>

class UpdateManager
{
    private:
        UpdateManager();
        static std::vector<IUpdate*> Updatable;

    public:
        static void Add(IUpdate*);
        static void Update();
        static void Remove(IUpdate*);
        static void Clear();
};

#endif