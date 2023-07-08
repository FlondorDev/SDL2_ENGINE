#include "../include/Camera.hpp"
#include "../include/Manager/GFXManager.hpp"
#include "../include/Manager/CameraManager.hpp"
#include "../include/GameObject.hpp"

Camera::Camera(std::string Name) : name{Name}, CameraRender{0, 0, 0, 0}
{
    if (CameraManager::MainCamera == nullptr)
        CameraManager::MainCamera = this;
    else
        CameraManager::Add(this, name);
}

Camera::~Camera()
{
    if (CameraManager::MainCamera == this)
        CameraManager::MainCamera = nullptr;
}

void Camera::Update()
{
    if (Target != nullptr)
    {
        if (CameraManager::MainCamera == this)
        {
            Utils::Lerp(&CameraRender, Vector2{
                -((Target->Position.X + Target->Width * 0.5f) - GFXManager::LogicWidth * 0.5f),
                -((Target->Position.Y + Target->Height * 0.5f) - GFXManager::LogicHeight * 0.5f)
            }, Clock::GetDeltaTime());
        }
    }
}

void Camera::SetTarget(GameObject *Target)
{
    if (CameraManager::MainCamera == this)
        this->Target = Target;
    Target->Camera = this;
}
