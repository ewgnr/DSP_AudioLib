#pragma once
#include <cmath>
#include "LinearOscillator.h"

class FMOscillator
{
public:
    FMOscillator() {}

    inline double play(double pCarrierFreq, double pModFreq, double pModIndex)
    {
        double modPhase = mModOsc.play(pModFreq);
        double carrierPhase = mCarrierOsc.play(pCarrierFreq);

        double modSignal = std::sin(2 * M_PI * modPhase) * pModIndex;
        double output = std::sin(2 * M_PI * carrierPhase + modSignal);

        return output;
    }

private:
    LinearOscillator mCarrierOsc;
    LinearOscillator mModOsc;
};
