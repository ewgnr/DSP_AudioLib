#pragma once
#include <cmath>

class SawToothGenerator
{
public:
    explicit SawToothGenerator(double pSampleRate = 44100.0)
        : phase(-1.0)
        , sampleRate(pSampleRate) {}

    inline double play(double pFreq)
    {
        const double output = phase;
        phase += (2.0 * pFreq) / sampleRate;
        if (phase >= 1.0)
            phase -= 2.0;
        return output;
    }

    inline void reset() { phase = -1.0; }

    inline void setSampleRate(double pSampleRate) { sampleRate = pSampleRate; }

private:
    double phase;
    double sampleRate;
};
