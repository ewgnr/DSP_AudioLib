#pragma once
#include "DelayBuffer.h"

class AudioFbkDelay
{
public:
    AudioFbkDelay() 
        : output(0.0)
        , maxDelaySamples(0) {}

    void init(int pMaxDelaySamples)
    {
        delay.init(pMaxDelaySamples);
        maxDelaySamples = pMaxDelaySamples;
        output = 0.0;
    }

    inline double play(double pIn, double pDelayTime, double pFbk)
    {
        double delaySamples = pDelayTime * maxDelaySamples;
        double delayed = delay.read(delaySamples);

        double writeSample = pIn + delayed * pFbk;
        delay.write(writeSample);

        output = delayed;
        return output;
    }

private:
    DelayBuffer delay;
    int maxDelaySamples;
    double output;
};
