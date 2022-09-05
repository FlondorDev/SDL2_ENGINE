#include "../include/Manager/ControllerManager.hpp"

std::vector<IController*> ControllerManager::Controllers {};

void ControllerManager::Input(const Uint8* keyboard_state_array){
    for (size_t i = 0; i < Controllers.size(); i++)
    {
       Controllers.at(i)->Input(keyboard_state_array);
    }
}

void ControllerManager::Add(IController* ctrl){
    Controllers.push_back(ctrl);
}

void ControllerManager::Remove(IController* ctrl){
    for (size_t i = 0; i < Controllers.size(); i++)
    {
        if(Controllers.at(i) == ctrl){
            Controllers.erase(Controllers.begin()+i);
        }
    }
}

void ControllerManager::Clear(){
   Controllers.clear();
}
