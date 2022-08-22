#include "../include/interfaces/IDraw.hpp"
#include "../include/Manager/DrawManager.hpp"


IDraw::IDraw(){
    DrawManager::Add(this);
}

IDraw::~IDraw(){
    DrawManager::Remove(this);
}

