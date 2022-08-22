#ifndef _CONTROLLERMANAGER_H_
#define _CONTROLLERMANAGER_H_

#include "../interfaces/IController.hpp"
#include <iostream>
#include <vector>

class ControllerManager
{
    private:
        ControllerManager();
        static std::vector<IController*> Controllers;

    public:
        static void Add(IController*);
        static void Input(const Uint8 *keyboard_state_array);
        static void Remove(IController*);
        static void Clear();
};

#endif