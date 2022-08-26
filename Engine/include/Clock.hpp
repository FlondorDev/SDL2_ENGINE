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
        Clock();

    public:
        static void SetFPS(int);
        static void StartTick();
        static void EndTick();
        static float GetFps();
        static double GetDeltaTime();
};


#endif