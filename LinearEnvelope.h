#pragma once

#include <vector>
#include <utility>

class LinearEnvelope 
{
public:
    LinearEnvelope() : currentTime(0.0), active(false), currentSegment(0) {}

    void set(const std::vector<std::pair<double, double>>& segments) 
    {
        this->segments = segments;
        currentTime = 0.0;
        currentSegment = 0;
        startValue = segments.empty() ? 0.0 : segments[0].second;
        active = !segments.empty();
    }

    void reset() 
    {
        currentTime = 0.0;
        currentSegment = 0;
        if (!segments.empty()) startValue = segments[0].second;
        active = !segments.empty();
    }

    double play(double dt) 
    {
        if (!active || segments.empty()) return segments.empty() ? 0.0 : segments.back().second;

        auto [segDuration, segTarget] = segments[currentSegment];
        double value = startValue + (segTarget - startValue) * (currentTime / segDuration);

        currentTime += dt;

        if (currentTime >= segDuration) 
        {
            currentTime -= segDuration;
            startValue = segTarget;
            currentSegment++;
            if (currentSegment >= segments.size()) 
            {
                active = false;
            }
        }

        return value;
    }

    bool isActive() const { return active; }

private:
    std::vector<std::pair<double, double>> segments;
    double currentTime;
    double startValue;
    size_t currentSegment;
    bool active;
};
