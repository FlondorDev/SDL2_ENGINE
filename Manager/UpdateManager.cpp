#include "../include/Manager/UpdateManager.hpp"

std::vector<IUpdate*> UpdateManager::Updatable {};

void UpdateManager::Update(){
    for (size_t i = 0; i < Updatable.size(); i++)
    {
       Updatable.at(i)->Update();
    }
}

void UpdateManager::Add(IUpdate* update){
    Updatable.push_back(update);
}

void UpdateManager::Remove(IUpdate* update){
    for (size_t i = 0; i < Updatable.size(); i++)
    {
        if(Updatable.at(i) == update){
            Updatable.erase(Updatable.begin()+i);
        }
    }
}

void UpdateManager::Clear(){
   Updatable.clear();
}
