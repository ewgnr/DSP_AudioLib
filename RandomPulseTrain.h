#pragma once

#include "PulseWaveGenerator.h"

class RandomPulseTrain 
{
public:
    RandomPulseTrain(double sampleRate = 44100.0) 
        : pulse(sampleRate)
		, sampleRate(sampleRate) {}

    double tick(double dt, double gap) 
    {
        double freq = 1.0 / gap;
        return (pulse.play(freq) > 0.0) ? 1.0 : 0.0;
    }

    void setPulseWidth(double pw) { pulse.setPulseWidth(pw); }

private:
    PulseWaveGenerator pulse;
    double sampleRate;
};
