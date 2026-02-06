#pragma once
#include "DelayBuffer.h"
#include <algorithm>

class AudioFbkDelay
{
public:
    explicit AudioFbkDelay(int pMaxDelaySamples = 0)
        : maxDelaySamples(pMaxDelaySamples)
    {
        if (pMaxDelaySamples > 0)
            delay.init(pMaxDelaySamples);
    }

    inline void init(int pMaxDelaySamples)
    {
        maxDelaySamples = pMaxDelaySamples;
        delay.init(maxDelaySamples);
    }

    inline double play(double pIn, double pDelayTime, double pFeedback)
    {
        if (maxDelaySamples <= 0)
            return 0.0;

        pDelayTime = std::clamp(pDelayTime, 0.0, 1.0);
        const double delayed = delay.read(pDelayTime * maxDelaySamples);
        delay.write(pIn + delayed * pFeedback);

        return delayed;
    }

    inline void reset()
    {
        delay.clear();
    }

private:
    DelayBuffer delay;
    int maxDelaySamples = 0;
};
