#pragma once
#include <cmath>

class Metronome
{
public:
    Metronome(double sampleRate = 44100.0)
        : phase(0.0)
        , sampleRate(sampleRate) {}

    inline double play(double freq)
    {
        if (freq <= 0.0) return 0.0;

        phase += freq / sampleRate;

        if (phase >= 1.0)
        {
            phase -= 1.0;
            return 1.0;
        }

        return 0.0;
    }

    inline void reset() { phase = 0.0; }

    inline void setSampleRate(double sr) { sampleRate = sr; }

private:
    double phase;
    double sampleRate;
};
