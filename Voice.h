#pragma once

class Voice
{
public:
    Voice()
        : freqHz(0.0)
        , remainingSamples(0)
        , active(false) { }

    inline void start(double frequency, double durationSec, double sampleRate) 
    {
        freqHz = frequency;
        remainingSamples = static_cast<int>(durationSec * sampleRate + 0.5);
        active = true;
    }

    inline void tick() 
    {
        if (active && remainingSamples > 0) 
        {
            --remainingSamples;

            if (remainingSamples <= 0) active = false;
        }
    }

    inline bool isActive() const { return active; }
    inline double getFrequency() const { return freqHz; }

private:
    double freqHz;
    int remainingSamples;
    bool active;
};
