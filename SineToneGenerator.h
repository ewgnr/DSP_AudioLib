#pragma once
#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class SineToneGenerator
{
public:
    explicit SineToneGenerator(double pSampleRate = 44100.0)
        : phase(0.0)
        , sampleRate(pSampleRate) {}

    inline double play(double pFreq)
    {
        const double sine = std::sin(phase * 2.0 * M_PI);
        phase += pFreq / sampleRate;
        if (phase >= 1.0)
            phase -= 1.0;
        return sine;
    }

    inline void reset() { phase = 0.0; }

    inline void setSampleRate(double pSampleRate) { sampleRate = pSampleRate; }

private:
    double phase;
    double sampleRate;
};
