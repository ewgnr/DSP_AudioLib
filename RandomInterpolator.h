#pragma once
#include <random>

class RandomInterpolator
{
public:
    explicit RandomInterpolator(double pLo = 0.0, double pHi = 1.0, double pInterval = 1.0)
        : lo(pLo)
        , hi(pHi)
        , interval(pInterval)
        , value(pLo)
        , prev(pLo)
        , rng(std::random_device{}())
        , dist(pLo, pHi)
        , t(0.0) {}

    inline double play(double pDt)
    {
        t += pDt;
        if (t >= interval)
        {
            prev = value;
            value = dist(rng);
            t -= interval;
        }

        const double alpha = t / interval;
        return prev * (1.0 - alpha) + value * alpha;
    }

    inline void reset()
    {
        t = 0.0;
        prev = value = lo;
    }

    inline void setRange(double pLo, double pHi)
    {
        lo = pLo;
        hi = pHi;
        dist = std::uniform_real_distribution<double>(lo, hi);
    }

    inline void setInterval(double pInterval)
    {
        interval = pInterval;
    }

private:
    double lo, hi;
    double interval;
    double t;
    double prev, value;
    std::mt19937 rng;
    std::uniform_real_distribution<double> dist;
};
