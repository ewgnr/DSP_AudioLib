#pragma once
#include <random>

class RandomUniform
{
public:
    RandomUniform(unsigned int seed = std::random_device{}())
        : rng(seed) {}

    inline double next(double lo, double hi)
    {
        std::uniform_real_distribution<double> dist(lo, hi);
        return dist(rng);
    }

    inline double play(double trigger, double lo, double hi)
    {
        if (trigger > 0.0) value = next(lo, hi);

        return value;
    }

    inline void reseed(unsigned int seed) { rng.seed(seed); }

private:
    std::mt19937 rng;
    double value = 0.0;
};
