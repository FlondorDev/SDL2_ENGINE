#include "include/Camera.hpp"
#include "include/Manager/GFXManager.hpp"
#include "include/Manager/CameraManager.hpp"
#include "include/GameObject.hpp"

Camera::Camera(std::string Name): name{Name} {
    if(CameraManager::MainCamera == nullptr)
        CameraManager::MainCamera = this;
    else CameraManager::Add(this, name);
}

Camera::~Camera(){
    if(CameraManager::MainCamera == this)
        CameraManager::MainCamera = nullptr;
}

void Camera::Update(){
    if(Target != nullptr){
        if(CameraManager::MainCamera == this){
            CameraRender.x = -((Target->Position.X + Target->Width / 2) - GFXManager::LogicWidth / 2);
            CameraRender.y = -((Target->Position.Y + Target->Height / 2) - GFXManager::LogicHeight / 2);
        }
    }
}

void Camera::SetTarget(GameObject* Target){
    if(CameraManager::MainCamera == this) this->Target = Target;
    Target->Camera = this;
}


