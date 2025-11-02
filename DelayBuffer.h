#pragma once
#include <vector>
#include <cmath>
#include <algorithm>

class DelayBuffer 
{
public:
    DelayBuffer() 
        : writePos(0)
        , maxSize(0) {}

    void init(size_t size) 
    {
        buffer.assign(size, 0.0);
        maxSize = size;
        writePos = 0;
    }

    inline void write(double sample) 
    {
        buffer[writePos] = sample;
        writePos = (writePos + 1) % maxSize;
    }

    inline double read(size_t delaySamples) const 
    {
        delaySamples = std::min(delaySamples, maxSize - 1); // clamp delay
        size_t readPos = (writePos + maxSize - delaySamples) % maxSize;

        return buffer[readPos];
    }

    inline double readInterp(double delaySamples) const 
    {
        int iDelay = static_cast<int>(delaySamples);
        double frac = delaySamples - iDelay;

        size_t indexA = (writePos + maxSize - iDelay - 1) % maxSize;
        size_t indexB = (indexA + 1) % maxSize;

        double sampleA = buffer[indexA];
        double sampleB = buffer[indexB];

        return sampleA + frac * (sampleB - sampleA);
    }

    inline void clear() 
    {
        std::fill(buffer.begin(), buffer.end(), 0.0);
        writePos = 0;
    }

    inline size_t size() const { return maxSize; }

private:
    std::vector<double> buffer;
    size_t writePos;
    size_t maxSize;
};
