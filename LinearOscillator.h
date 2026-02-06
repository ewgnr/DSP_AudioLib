#pragma once

class LinearOscillator
{
public:
    explicit LinearOscillator(double pSampleRate = 44100.0)
        : phase(0.0)
        , sampleRate(pSampleRate) {}

    inline double play(double pFreq)
    {
        const double out = phase;
        phase += pFreq / sampleRate;
        if (phase >= 1.0) phase -= 1.0;
        return out;
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
