#pragma once
#include "Voice.h"

template <typename T = Voice, int MaxVoices = 16>
class VoicePool
{
public:
    constexpr VoicePool() = default;

    inline T* allocate()
    {
        for (int i = 0; i < MaxVoices; ++i)
        {
            if (!voices[i].isActive())
                return &voices[i];
        }
        return nullptr;
    }

    inline T& operator[](int index) { return voices[index]; }

    constexpr inline int size() const { return MaxVoices; }

private:
    T voices[MaxVoices]{};
};
