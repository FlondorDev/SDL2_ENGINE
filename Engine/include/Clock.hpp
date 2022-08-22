#ifndef _CLOCK_H_
#define _CLOCK_H_
#include <SDL.h>

class Clock
{
    private:
        static Uint64 START;
        static Uint64 END;
        static Uint32 lastUpdate;
        static Uint32 current;
        static double deltaTime;
        static int FPS_TARGET;
        static int FRAME_DELAY;
        Clock();

    public:
        static void SetFPS(int);
        static void StartTick();
        static void EndTick();
        static inline float GetFps();
        static inline double GetDeltaTime();
};

inline float Clock::GetFps(){
    return 1.0f / ((SDL_GetPerformanceCounter() - START) / (float)SDL_GetPerformanceFrequency());
}

inline double Clock::GetDeltaTime(){
    return deltaTime;
}


#endif