#pragma once
#include "PulseWaveGenerator.h"

class RandomPulseTrain
{
public:
    explicit RandomPulseTrain(double pSampleRate = 44100.0)
        : pulse(pSampleRate)
        , sampleRate(pSampleRate) {}

    inline double play(double pDt, double pGap)
    {
        const double freq = 1.0 / pGap;
        return (pulse.play(freq) > 0.0) ? 1.0 : 0.0;
    }

    inline void setPulseWidth(double pPulseWidth)
    {
        pulse.setPulseWidth(pPulseWidth);
    }

    inline void reset()
    {
        pulse.reset();
    }

private:
    PulseWaveGenerator pulse;
    double sampleRate;
};
