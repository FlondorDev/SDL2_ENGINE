
#include "../include/interfaces/IController.hpp"
#include "../include/Manager/ControllerManager.hpp"

IController::IController(){
    ControllerManager::Add(this);
}

IController::~IController(){
    ControllerManager::Remove(this);
}
