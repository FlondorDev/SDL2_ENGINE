#ifndef _CLOCK_H_
#define _CLOCK_H_
#include <SDL.h>

class Clock
{
    private:
        static int FPS_TARGET;
        static int FRAME_DELAY;
        static Uint32 fpsTimer;
        static Uint32 capTimer;
        static int countedFrames;
        static float avgFPS;
        Clock();

    public:
        static void SetFPS(int);
        static void StartTick();
        static void EndTick();
        static float GetFps();
        static float GetAvgFps();
        static double GetDeltaTime();
};


#endif