#pragma once
#include <vector>
#include "ModalFilter.h"
#include "ofMain.h"

class ModalBank
{
public:
    inline void setup(size_t pNumModes, double pSampleRate)
    {
        nodes.resize(pNumModes);
        weights.assign(pNumModes, 1.0 / pNumModes);
        excitation.assign(pNumModes, 0.0);
        output.assign(pNumModes, 0.0);

        for (auto & n : nodes)
            n.setSampleRate(pSampleRate);
    }

    inline void initRandom()
    {
        for (auto & n : nodes)
        {
            const double frq = 200.0 + 800.0 * ofRandom(1.0);
            const double q   = 5.0 + 10.0 * ofRandom(1.0);
            n.init(frq, q, 0.05);
        }
    }

    inline void setParams(size_t pIndex, double pFrq, double pQ, double pAmp)
    {
        if (pIndex < nodes.size())
            nodes[pIndex].setParams(pFrq, pQ, pAmp);
    }

    inline void excite(size_t pIndex, double pIn)
    {
        if (pIndex < excitation.size())
            excitation[pIndex] += pIn;
    }

    inline double play()
    {
        double sum = 0.0;

        for (size_t i = 0; i < nodes.size(); i++)
        {
            output[i] = nodes[i].play(excitation[i]);
            sum += output[i] * weights[i];
            excitation[i] = 0.0;
        }

        return sum;
    }

    inline const std::vector<double> & getOutput() const
    {
        return output;
    }

private:
    std::vector<ModalFilter> nodes;
    std::vector<double> weights;
    std::vector<double> excitation;
    std::vector<double> output;
};
