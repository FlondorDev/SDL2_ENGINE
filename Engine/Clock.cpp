#include "include/Clock.hpp"

int Clock::FPS_TARGET = 60;
int Clock::FRAME_DELAY = 1000 / FPS_TARGET;
int Clock::countedFrames = FPS_TARGET;
float Clock::avgFPS = 0;
Uint32 Clock::fpsTimer = SDL_GetTicks();
Uint32 Clock::capTimer = 0;


void Clock::StartTick(){
    capTimer = SDL_GetTicks();

    avgFPS = countedFrames / ( (SDL_GetTicks() - fpsTimer) / 1000.f );
    if( avgFPS > 2000000 )
    {
        avgFPS = 0;
    }

}

double Clock::GetDeltaTime(){
    return ( (SDL_GetTicks() - capTimer) / 1000.f );
}

float Clock::GetFps(){
    return 1000 / (SDL_GetTicks() - capTimer);
}

float Clock::GetAvgFps(){
    return avgFPS;
}

void Clock::EndTick(){
    // Set updated time
    ++countedFrames;

    // Cap to 60 FPS
    int frameTicks = (SDL_GetTicks() - capTimer);
    if( frameTicks < FRAME_DELAY )
    {
        //Wait remaining time
        SDL_Delay( FRAME_DELAY - frameTicks );
    }

}

void Clock::SetFPS(int fps){
    FPS_TARGET = fps;
    FRAME_DELAY = 1000 / fps;
}