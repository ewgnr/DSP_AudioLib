#pragma once
#include <cmath>

class SawToothGenerator 
{
public:
    SawToothGenerator(double sampleRate = 44100.0)
        : phase(-1.0)
        , sampleRate(sampleRate) {}

    inline double play(double pFreq) 
    {
        double output = phase;
        phase += (2.0 * pFreq) / sampleRate;
        if (phase >= 1.0) phase -= 2.0;

        return output;
    }

    inline void reset() { phase = -1.0; }

    inline void setSampleRate(double sr) { sampleRate = sr; }

private:
    double phase;
    double sampleRate;
};
