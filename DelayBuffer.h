#pragma once
#include <vector>
#include <algorithm>

class DelayBuffer
{
public:
    explicit DelayBuffer(size_t pMaxSize = 0)
        : writePos(0)
        , maxSize(pMaxSize)
    {
        if (pMaxSize > 0)
            init(pMaxSize);
    }

    inline void init(size_t pMaxSize)
    {
        buffer.assign(pMaxSize, 0.0);
        maxSize = pMaxSize;
        writePos = 0;
    }

    inline void write(double pSample)
    {
        buffer[writePos] = pSample;
        writePos = (writePos + 1) % maxSize;
    }

    inline double read(size_t pDelaySamples) const
    {
        pDelaySamples = std::min(pDelaySamples, maxSize - 1);
        size_t readPos = (writePos + maxSize - pDelaySamples) % maxSize;
        return buffer[readPos];
    }

    inline double readInterp(double pDelaySamples) const
    {
        int iDelay = static_cast<int>(pDelaySamples);
        double frac = pDelaySamples - iDelay;

        size_t indexA = (writePos + maxSize - iDelay - 1) % maxSize;
        size_t indexB = (indexA + 1) % maxSize;

        return buffer[indexA] + frac * (buffer[indexB] - buffer[indexA]);
    }

    inline void clear()
    {
        std::fill(buffer.begin(), buffer.end(), 0.0);
        writePos = 0;
    }

    inline size_t size() const { return maxSize; }

private:
    std::vector<double> buffer;
    size_t writePos = 0;
    size_t maxSize = 0;
};
