#pragma once

class Voice
{
public:
    explicit Voice()
        : freqHz(0.0)
        , remainingSamples(0)
        , active(false) {}

    inline void start(double pFrequency, double pDurationSec, double pSampleRate)
    {
        freqHz = pFrequency;
        remainingSamples = static_cast<int>(pDurationSec * pSampleRate + 0.5);
        active = true;
    }

    inline void play()
    {
        if (!active || remainingSamples <= 0) return;

        --remainingSamples;
        if (remainingSamples <= 0) active = false;
    }

    inline bool isActive() const { return active; }
    inline double getFrequency() const { return freqHz; }

private:
    double freqHz;
    int remainingSamples;
    bool active;
};
