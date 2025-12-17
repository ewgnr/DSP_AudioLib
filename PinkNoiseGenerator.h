#pragma once
#include <random>
#include <algorithm>

class PinkNoiseGenerator
{
public:
    PinkNoiseGenerator(double amplitude = 1.0)
        : amp(amplitude)
    {
        reset();
    }

    inline double play()
    {
        double white = dist(rng) * amp;
        double pink = 0.5 * white + 0.5 * last;
        last = pink;
        return pink;
    }

    inline void reset() { last = 0.0; }

    inline void setAmplitude(double a) { amp = a; }

private:
    std::mt19937 rng{std::random_device{}()};
    std::uniform_real_distribution<double> dist{-1.0,1.0};
    double last = 0.0;
    double amp;
};
