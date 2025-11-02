class LinearOscillator
{
public:
    LinearOscillator(double sr = 44100.0) 
        : phase(0.0)
        , sampleRate(sr) {}

    inline double play(double freq)
    {
        double out = phase;
        phase += freq / sampleRate;
        if (phase >= 1.0) phase -= 1.0;
        
        return out;
    }

private:
    double phase;
    double sampleRate;
};
