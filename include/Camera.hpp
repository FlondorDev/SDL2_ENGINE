#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <SDL.h>

class GameObject;

class Camera
{
    public:
        Camera();
        ~Camera();
        SDL_Rect CameraRender;
        void Update();
        GameObject* Target;

};


#endif