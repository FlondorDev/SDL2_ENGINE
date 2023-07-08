#include "../../include/interfaces/IUpdate.hpp"
#include "../../include/Manager/UpdateManager.hpp"


IUpdate::IUpdate(){
    UpdateManager::Add(this);
}

IUpdate::~IUpdate(){
    UpdateManager::Remove(this);
}

