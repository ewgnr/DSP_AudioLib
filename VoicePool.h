#pragma once
#include "Voice.h"

template <int MaxVoices>
class VoicePool
{
public:
    inline Voice * allocate()
    {
        for (int i = 0; i < MaxVoices; ++i)
        {
            if (!voices[i].isActive())
                return &voices[i];
        }
        return nullptr;
    }

    inline Voice & operator[](int index) { return voices[index]; }
    inline constexpr int size() const { return MaxVoices; }

private:
    Voice voices[MaxVoices];
};
