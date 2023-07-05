#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <SDL.h>
#include <iostream>

class GameObject;

class Camera
{
    private:
        std::string name;
    public:
        Camera(std::string name);
        ~Camera();
        SDL_FRect CameraRender;
        void Update();
        GameObject* Target;
        void SetTarget(GameObject* Target);

};


#endif