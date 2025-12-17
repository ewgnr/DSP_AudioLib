#pragma once
#include <cmath>

class PulseWaveGenerator 
{
public:
    PulseWaveGenerator(double sampleRate = 44100.0, double pulseWidth = 0.5)
        : phase(0.0) 
        , sampleRate(sampleRate)
        , pulseWidth(pulseWidth) {}

    inline double play(double pFreq) 
    {
        double output = (phase < pulseWidth) ? 1.0 : -1.0; // pulse wave -1 to 1
        phase += pFreq / sampleRate;
        if (phase >= 1.0) phase -= 1.0;

        return output;
    }


    inline void reset() { phase = 0.0; }
    inline void setSampleRate(double sr) { sampleRate = sr; }
    inline void setPulseWidth(double pw) 
    {
        if (pw < 0.0) pw = 0.0;
        if (pw > 1.0) pw = 1.0;
        pulseWidth = pw;
    }

private:
    double phase;
    double sampleRate;
    double pulseWidth;
};
