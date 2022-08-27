#ifndef _IUPDATE_H_
#define _IUPDATE_H_
#include <SDL.h>

class IUpdate
{
    protected:
        IUpdate();
        ~IUpdate();

    public:
        virtual void Update() {}
};  

#endif