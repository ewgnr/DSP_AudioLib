#pragma once
#include <cmath>
#include <iostream>

class ModalFilter 
{
public:
    ModalFilter(double sampleRate = 44100.0)
        : x1(0)
        , y1(0)
        , y2(0)
        , alpha(0)
        , beta(0)
        , sum(0)
        , frq(0)
        , q(0)
        , amp(0)
        , out(0)
        , sampleRate(sampleRate) {}

    void init(double pFrq, double pQ, double pAmp) 
    {
        frq = pFrq;
        q = pQ;
        amp = pAmp;

        if (sampleRate / frq < M_PI) 
        {
            std::cerr << "Warning: Filter may be unstable (sr/frq < pi)" << std::endl;
        }

        double omega = 2.0 * M_PI * frq;
        alpha = sampleRate / omega;
        beta = alpha * alpha;
    }

    inline double play(double pIn) 
    {
        x1 = pIn;

        sum = (-(1.0 - 2.0 * beta) * y1 + x1 - (beta - alpha / (2.0 * q)) * y2) / (beta + alpha / (2.0 * q));
        y2 = y1;
        y1 = sum;

        out = sum * sampleRate / (2.0 * 2.0 * M_PI * frq) * amp; // normalizing factor
        return out;
    }

    inline void reset() { x1 = y1 = y2 = sum = out = 0.0; }

    inline void setSampleRate(double sr) { sampleRate = sr; }

private:
    double x1, y1, y2;
    double alpha, beta, sum;
    double frq, q, amp, out;
    double sampleRate;
};
