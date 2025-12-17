#pragma once
#include <random>

class RandomInterpolator
{
public:
    RandomInterpolator(double lo = 0.0, double hi = 1.0, double intervalSec = 1.0)
        : lo(lo)
		, hi(hi)
		, interval(intervalSec)
		, value(lo)
		, prev(lo)
		, rng(std::random_device{}())
		, dist(lo, hi) {}

    inline double play(double dt)
    {
        t += dt;
        if (t >= interval)
        {
            prev = value;
            value = dist(rng);
            t -= interval;
        }

        double alpha = t / interval;
        return prev * (1.0 - alpha) + value * alpha;
    }

    inline void reset()
    {
        t = 0.0;
        prev = value = lo;
    }

    inline void setRange(double newLo, double newHi)
    {
        lo = newLo;
        hi = newHi;
        dist = std::uniform_real_distribution<double>(lo, hi);
    }

    inline void setInterval(double newInterval) { interval = newInterval; }

private:
    double lo, hi;
    double interval;
    double t = 0.0;
    double prev, value;
    std::mt19937 rng;
    std::uniform_real_distribution<double> dist;
};
