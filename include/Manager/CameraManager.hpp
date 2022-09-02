#ifndef _CAMERAMANAGER_H_
#define _CAMERAMANAGER_H_

#include "../interfaces/IUpdate.hpp"
#include "../Camera.hpp"
#include "../Structs/Vector2.hpp"
#include <iostream>
#include <map>

class CameraManager
{
    private:
        CameraManager();
        static std::map<std::string, Camera*> Cameras;

    public:
        static Camera* MainCamera;
        static Camera* Get(std::string key);
        static void Add(Camera* camera, std::string name);
        static void Update();
        static void Remove(std::string key);
        static void Clear();
};

#endif