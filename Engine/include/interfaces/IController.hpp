#ifndef _ICONTROLLER_H_
#define _ICONTROLLER_H_
#include <SDL.h>

class IController
{
    protected:
        IController();
        ~IController();

    public:
        virtual void Input(const Uint8 *keyboard_state_array) {}
};

#endif