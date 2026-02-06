#pragma once
#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class OnePoleLoPassFilter
{
public:
    explicit OnePoleLoPassFilter(double pSampleRate = 44100.0)
        : out(0.0)
        , sampleRate(pSampleRate) {}

    inline double play(double pIn, double pCutoffHz)
    {
        const double RC = 1.0 / (2.0 * M_PI * pCutoffHz);
        const double dt = 1.0 / sampleRate;
        const double alpha = dt / (RC + dt);

        out += alpha * (pIn - out);
        return out;
    }

    inline void reset()
    {
        out = 0.0;
    }

    inline void setSampleRate(double pSampleRate)
    {
        sampleRate = pSampleRate;
    }

private:
    double out = 0.0;
    double sampleRate;
};
