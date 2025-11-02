#pragma once
#include <cmath>

class OnePoleLoPassFilter 
{
public:
    OnePoleLoPassFilter(double sampleRate = 44100.0)
        : out(0.0)
        , sampleRate(sampleRate) {}

    inline double play(double pIn, double pCutoffHz) 
    {
        double RC = 1.0 / (2.0 * M_PI * pCutoffHz);
        double dt = 1.0 / sampleRate;
        double alpha = dt / (RC + dt);

        out += alpha * (pIn - out);
        return out;
    }

    inline void reset() { out = 0.0; }

    inline void setSampleRate(double sr) { sampleRate = sr; }

private:
    double out;
    double sampleRate;
};
