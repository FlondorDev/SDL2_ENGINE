#ifndef _CLOCK_H_
#define _CLOCK_H_
#include <SDL.h>

class Clock
{
    private:
        static int FPS_TARGET;
        static Uint64 FRAME_DELAY;
        static Uint64 capTimer;
        static Uint64 deltaTimer;
        Clock();

    public:
        static float DeltaMultiplier;
        static void SetFPS(int);
        static void StartTick();
        static void EndTick();
        static float GetFps();
        static double GetDeltaTime();
};


#endif