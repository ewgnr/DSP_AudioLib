#pragma once
#include <cmath>

class Metronome
{
public:
    explicit Metronome(double pSampleRate = 44100.0)
        : phase(0.0)
        , sampleRate(pSampleRate) {}

    inline double play(double pFreq)
    {
        if (pFreq <= 0.0)
            return 0.0;

        phase += pFreq / sampleRate;

        if (phase >= 1.0)
        {
            phase -= 1.0;
            return 1.0;
        }

        return 0.0;
    }

    inline void reset()
    {
        phase = 0.0;
    }

    inline void setSampleRate(double pSampleRate)
    {
        sampleRate = pSampleRate;
    }

private:
    double phase = 0.0;
    double sampleRate;
};
