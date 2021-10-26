#include "PushButtonMulticlick.h"

PushButtonMulticlick::PushButtonMulticlick(
    uint8_t pin,
    uint8_t id)
    : Button(pin, id),
      OneButton(pin, true),
      _lastReadState(false, false)
{
    traceme;
}

PushButtonMulticlick::~PushButtonMulticlick()
{
    traceme;
}

void PushButtonMulticlick::init()
{
    traceme;

    // do nothing
}

void PushButtonMulticlick::tick()
{
    OneButton::tick();
}

// events
void PushButtonMulticlick::clickEvent()
{
    PlatformFeatures::println("singleClick() detected.");
    _lastReadState = StateChangedResult(true, true, 1);
}
void PushButtonMulticlick::pressEvent()
{
    PlatformFeatures::println("pressEvent() detected.");
}
void PushButtonMulticlick::longPressStartEvent()
{
    PlatformFeatures::println("longPressStartEvent() detected.");
}
void PushButtonMulticlick::longPressStopEvent()
{
    PlatformFeatures::println("longPressStopEvent() detected.");
    _lastReadState = StateChangedResult(true, true, 3);
}
void PushButtonMulticlick::duringLongPressEvent()
{
    PlatformFeatures::println("duringLongPressEvent() detected.");
}
void PushButtonMulticlick::doubleClickEvent()
{
    PlatformFeatures::println("doubleClick() detected.");
    _lastReadState = StateChangedResult(true, true, 2);
}

StateChangedResult PushButtonMulticlick::stateIsChanged()
{
    auto s = _lastReadState;
    _lastReadState = StateChangedResult(false, false);

    return s;
}
