#ifndef LedTurnConfig_h
#define LedTurnConfig_h

#include <UnitConfiguration.h>

class LedTurnConfig : public IDeviceTurnConfiguration<FastLedLight>
{
private:
    void set(CRGB color)
    {
        fill_solid(_device->ledController->leds(), _device->ledController->size(), color);
        _device->ledController->showLeds(1);
    }

public:
    LedTurnConfig()
    {
        traceme;
    }

    bool on(uint8_t requestorId) override
    {
        traceme;

        auto color = CRGB::Red;
        switch (requestorId)
        {
        case 1:
            color = CRGB::Green;
            break;

        case 2:
            color = CRGB::White;
            break;

        case 3:
            color = CRGB::Blue;
            break;
        }

        set(color);
        return true;
    }

    bool off(uint8_t requestorId) override
    {
        traceme;

        (void)requestorId;

        set(CRGB::Black);
        return true;
    }
};

#endif
