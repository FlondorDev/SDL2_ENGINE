#include "../include/Manager/DrawManager.hpp"

std::vector<IDraw*> DrawManager::Drawable {};

void DrawManager::Draw(){
    for (size_t i = 0; i < Drawable.size(); i++)
    {
       Drawable.at(i)->Draw();
    }
}

void DrawManager::Add(IDraw* draw){
    Drawable.push_back(draw);
}

void DrawManager::Remove(IDraw* draw){
    for (size_t i = 0; i < Drawable.size(); i++)
    {
        if(Drawable.at(i) == draw){
            Drawable.erase(Drawable.begin()+i);
        }
    }
}

void DrawManager::Clear(){
   Drawable.clear();
}
