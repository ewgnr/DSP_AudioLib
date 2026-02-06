#pragma once
#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class Resonator
{
public:
    explicit Resonator(double pSampleRate = 44100.0)
        : fs(pSampleRate)
        , a1(0.0), a2(0.0), b0(0.0)
        , y1(0.0), y2(0.0)
        , x1(0.0), x2(0.0) {}

    inline void setParams(double pFreq, double pBandwidth)
    {
        const double omega = 2.0 * M_PI * pFreq / fs;
        const double r = std::exp(-M_PI * pBandwidth / fs);
        a1 = -2.0 * r * std::cos(omega);
        a2 = r * r;
        b0 = std::sin(omega);
    }

    inline double play(double pIn)
    {
        const double y = b0 * pIn - a1 * y1 - a2 * y2;
        y2 = y1;
        y1 = y;
        return y;
    }

    inline void reset()
    {
        y1 = y2 = x1 = x2 = 0.0;
    }

    inline void setSampleRate(double pSampleRate)
    {
        fs = pSampleRate;
    }

private:
    double fs;
    double a1, a2, b0;
    double y1, y2, x1, x2;
};
