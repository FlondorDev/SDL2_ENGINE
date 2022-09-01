#include "include/Camera.hpp"
#include "include/Manager/GFXManager.hpp"
#include "include/GameObject.hpp"

Camera::Camera() {
    CameraRender.w = GFXManager::LogicWidth;
    CameraRender.h = GFXManager::LogicHeight;

    if(GFXManager::MainCamera == nullptr)
        GFXManager::MainCamera = this;
}

Camera::~Camera(){
    if(GFXManager::MainCamera == this)
        GFXManager::MainCamera = nullptr;
}

void Camera::Update(){
    if(Target != nullptr){
        CameraRender.x = (Target->Position.X + Target->Width / 2) - GFXManager::LogicWidth / 2;
        CameraRender.y = (Target->Position.Y + Target->Height / 2) - GFXManager::LogicHeight / 2;
    }
}


