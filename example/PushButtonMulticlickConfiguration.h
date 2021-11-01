#ifndef PushButtonMulticlickConfiguration_h
#define PushButtonMulticlickConfiguration_h

#include <UnitConfiguration.h>
#include <UnitConfigurationButtonMulticlick.h>
#include "LedTurnConfig.h"
#include "TestControllerHandler.h"

class PushButtonMulticlickConfiguration : public IConfiguration<1>
{
public:
    PushButtonMulticlickConfiguration()
    {
        auto button = new PushButtonMulticlick(2, BUTTON_ID);
        button->setClickTicks(250);
        button->setPressTicks(500);
        button->attachClick(__onPushButtonMulticlickClicked, button);
        button->attachDoubleClick(__onPushButtonMulticlickDoubleClicked, button);
        button->attachLongPressStop(__onPushButtonMulticlickLongPressStopped, button);

        add(new WorkUnit(
            new IDevice *[2]
            {
                new GenericDevice(7), // lights
                    FastLedLight::create<6>(5, new LedTurnConfig())
            },
            2,
            button,
            new TestControllerHandler()));
    }
};

#endif
