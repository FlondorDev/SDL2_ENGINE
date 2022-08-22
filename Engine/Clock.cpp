#include "include/Clock.hpp"

Uint64 Clock::START = SDL_GetPerformanceCounter();
Uint64 Clock::END = 0;
Uint32 Clock::lastUpdate = SDL_GetTicks();
Uint32 Clock::current = 0;
double Clock::deltaTime = 0;
int Clock::FPS_TARGET = 60;
int Clock::FRAME_DELAY = 1000 / FPS_TARGET;

void Clock::StartTick(){
    START = SDL_GetPerformanceCounter();
    current = SDL_GetTicks();

    deltaTime = (current - lastUpdate) / 1000.0f;
}

void Clock::EndTick(){
    // Set updated time
    lastUpdate = current;

    END = SDL_GetPerformanceCounter();
    // Cap to 60 FPS
    SDL_Delay(floor(FRAME_DELAY - ((END - START) / (float)SDL_GetPerformanceFrequency() * 1000.0f)));

}

void Clock::SetFPS(int fps){
    FPS_TARGET = fps;
    FRAME_DELAY = 1000 / fps;
}
