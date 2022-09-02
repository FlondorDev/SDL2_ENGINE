#include "../include/Manager/CameraManager.hpp"

std::map<std::string, Camera*> CameraManager::Cameras {};

Camera* CameraManager::MainCamera {nullptr};

void CameraManager::Update(){
    if(MainCamera != nullptr){
        MainCamera->Update();
    }
}

Camera* CameraManager::Get(std::string key){
    return Cameras.at(key);
}

void CameraManager::Add(Camera* camera, std::string name){
     Cameras.insert(std::pair<std::string,Camera*>(name,camera));
}

void CameraManager::Remove(std::string key){
    Cameras.erase(key);
}

void CameraManager::Clear(){
   Cameras.clear();
}
