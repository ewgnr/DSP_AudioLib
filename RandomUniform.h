#pragma once
#include <random>
#include <algorithm>

class RandomUniform
{
public:
    explicit RandomUniform(unsigned int pSeed = std::random_device{}())
        : rng(pSeed) {}

    inline double next(double pLo, double pHi)
    {
        std::uniform_real_distribution<double> dist(pLo, pHi);
        return dist(rng);
    }

    inline double play(double pTrigger, double pLo, double pHi)
    {
        if (pTrigger > 0.0)
            value = next(pLo, pHi);

        return value;
    }

    inline void reseed(unsigned int pSeed)
    {
        rng.seed(pSeed);
    }

private:
    std::mt19937 rng;
    double value = 0.0;
};
