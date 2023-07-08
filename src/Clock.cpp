#include "../include/Clock.hpp"

int Clock::FPS_TARGET = 60;
Uint64 Clock::FRAME_DELAY = 1000 / FPS_TARGET;
Uint64 Clock::capTimer = 0;
Uint64 Clock::deltaTimer = 0;
float Clock::DeltaMultiplier = 50;

void Clock::StartTick()
{
    deltaTimer = capTimer;
    capTimer = SDL_GetTicks64();
}

double Clock::GetDeltaTime()
{
    return ((capTimer - deltaTimer) / 1000.0) * DeltaMultiplier;
}

float Clock::GetFps()
{
    return 1000 / (capTimer - deltaTimer);
}

void Clock::EndTick()
{
    // Cap to 60 FPS
    Uint64 frameTicks = (SDL_GetTicks64() - capTimer);
    if (frameTicks < FRAME_DELAY)
    {
        // Wait remaining time
        SDL_Delay(FRAME_DELAY - frameTicks);
    }
}

void Clock::SetFPS(int fps)
{
    FPS_TARGET = fps;
    FRAME_DELAY = 1000 / fps;
}