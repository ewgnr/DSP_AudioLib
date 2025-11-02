#pragma once
#include <cmath>

class SineToneGenerator 
{
public:
    SineToneGenerator(double sampleRate = 44100.0)
        : phase(0.0)
        , sampleRate(sampleRate) {}

    inline double play(double pFreq) 
    {
        double sine = std::sin(phase * 2.0 * M_PI);
        phase += pFreq / sampleRate;

        if (phase >= 1.0) phase -= 1.0;

        return sine;
    }

    inline void reset() { phase = 0.0; }

    inline void setSampleRate(double sr) { sampleRate = sr; }

private:
    double phase;
    double sampleRate;
};
