#pragma once
#include <cmath>
#include "LinearOscillator.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

class FMOscillator
{
public:
    explicit FMOscillator() = default;

    inline double play(double pCarrierFreq, double pModFreq, double pModIndex)
    {
        const double modPhase = mModOsc.play(pModFreq);
        const double carrierPhase = mCarrierOsc.play(pCarrierFreq);

        const double modSignal = std::sin(2.0 * M_PI * modPhase) * pModIndex;
        const double output = std::sin(2.0 * M_PI * carrierPhase + modSignal);

        return output;
    }

    inline void reset()
    {
        mCarrierOsc.reset();
        mModOsc.reset();
    }

    inline void setSampleRate(double pSampleRate)
    {
        mCarrierOsc.setSampleRate(pSampleRate);
        mModOsc.setSampleRate(pSampleRate);
    }

private:
    LinearOscillator mCarrierOsc;
    LinearOscillator mModOsc;
};
