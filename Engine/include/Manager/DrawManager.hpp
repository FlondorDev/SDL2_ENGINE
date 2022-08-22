#ifndef _DRAWMANAGER_H_
#define _DRAWMANAGER_H_

#include "../interfaces/IDraw.hpp"
#include <iostream>
#include <vector>

class DrawManager
{
    private:
        DrawManager();
        static std::vector<IDraw*> Drawable;

    public:
        static void Add(IDraw*);
        static void Draw();
        static void Remove(IDraw*);
        static void Clear();
};

#endif