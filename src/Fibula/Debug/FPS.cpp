#include <Fibula/Debug/FPS.hpp>

#include <SDL2/SDL_timer.h>

using namespace Fibula::Debug;

void FPS::calculate(float &fps, float &frameTime)
{
    static const int NUMBER_SAMPLES = 100;
    static float frameTimes[NUMBER_SAMPLES];
    static int currentFrame = 0;

    static float previousTicks = SDL_GetTicks();
    float currentTicks;

    currentTicks = SDL_GetTicks();

    frameTime = currentTicks - previousTicks;
    frameTimes[currentFrame % NUMBER_SAMPLES] = frameTime;

    previousTicks = currentTicks;

    int count;

    if (currentFrame < NUMBER_SAMPLES) {
        count = currentFrame;
    } else {
        count = NUMBER_SAMPLES;
    }

    float frameTimeAverage = 0;

    for (int i = 0; i < count; ++i) {
        frameTimeAverage += frameTimes[i];
    }

    frameTimeAverage /= count;

    if (frameTimeAverage > 0) {
        fps = 1000.0f / frameTimeAverage;
    } else {
        fps = 60.0f;
    }

    currentFrame++;
}
