#pragma once
#include <cmath>
#include <algorithm>

class PulseWaveGenerator
{
public:
    explicit PulseWaveGenerator(double pSampleRate = 44100.0, double pPulseWidth = 0.5)
        : phase(0.0)
        , sampleRate(pSampleRate)
        , pulseWidth(std::clamp(pPulseWidth, 0.0, 1.0)) {}

    inline double play(double pFreq)
    {
        const double output = (phase < pulseWidth) ? 1.0 : -1.0;
        phase += pFreq / sampleRate;
        if (phase >= 1.0)
            phase -= 1.0;
        return output;
    }

    inline void reset()
    {
        phase = 0.0;
    }

    inline void setSampleRate(double pSampleRate)
    {
        sampleRate = pSampleRate;
    }

    inline void setPulseWidth(double pPulseWidth)
    {
        pulseWidth = std::clamp(pPulseWidth, 0.0, 1.0);
    }

private:
    double phase = 0.0;
    double sampleRate;
    double pulseWidth;
};
