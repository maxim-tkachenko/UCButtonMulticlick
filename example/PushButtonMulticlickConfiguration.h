#ifndef PushButtonMulticlickConfiguration_h
#define PushButtonMulticlickConfiguration_h

#include <UnitConfiguration.h>
#include "UnitConfigurationButtonMulticlick.h"
#include "LedTurnConfig.h"
#include "TestControllerHandler.h"

class PushButtonMulticlickConfiguration : public IConfiguration<1>
{
public:
    PushButtonMulticlickConfiguration()
    {
        add(new WorkUnit(
            FastLedLight::create<6>(5, new LedTurnConfig()),
            new PushButtonMulticlick(2, BUTTON_ID),
            new TestControllerHandler()));
    }
};

#endif
