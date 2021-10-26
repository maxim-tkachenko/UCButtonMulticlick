#ifndef BathroomControllerHandler_h
#define BathroomControllerHandler_h

#include "IHandler.h"
#include "Definitions.h"

#define BUTTON_ID 55

class TestControllerHandler : public IHandler
{
public:
    bool execute(HANDLER_ARGS) override
    {
        (void)results;

        for (uint8_t ci = 0; ci < controllersCount; ci++)
        {
            auto stateChanges = controllers[ci]->stateIsChanged();
            if (stateChanges.isChanged)
            {
                PlatformFeatures::println("controller triggerred");
                if (controllers[ci]->getId() == BUTTON_ID)
                {
                    for (uint8_t di = 0; di < devicesCount; di++)
                    {
                        devices[di]->switchState(true, stateChanges.newStateCode);
                    }

                    return true;
                }
            }
        }

        return false;
    }
};

#endif
