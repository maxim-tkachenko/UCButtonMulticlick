#include "PushButtonMulticlick.h"

PushButtonMulticlick::PushButtonMulticlick(
    uint8_t pin,
    uint8_t id)
    : Button(pin, id),
      OneButton(pin, true), // connects to digital pin and GND, which is active low and uses the internal pull-up resistor.
      _lastReadState(false, false)
{
    traceme;
}

PushButtonMulticlick::~PushButtonMulticlick()
{
    traceme;
}

void PushButtonMulticlick::setLastReadState(uint8_t stateCode)
{
    _lastReadState = StateChangedResult(true, true, stateCode);
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

StateChangedResult PushButtonMulticlick::stateIsChanged()
{
    auto s = _lastReadState;
    _lastReadState = StateChangedResult(false, false);

    return s;
}

void PushButtonMulticlick::attachClick()
{
    traceme;
    OneButton::attachClick(onClick, this);
}

void PushButtonMulticlick::attachDoubleClick()
{
    traceme;
    OneButton::attachDoubleClick(onDoubleClick, this);
}

void PushButtonMulticlick::attachMultiClick()
{
    traceme;
    OneButton::attachMultiClick(onMultiClick, this);
}

void PushButtonMulticlick::attachLongPressStart()
{
    traceme;
    OneButton::attachLongPressStart(onLongPressStart, this);
}

void PushButtonMulticlick::attachLongPressStop()
{
    traceme;
    OneButton::attachLongPressStop(onLongPressStop, this);
}

void PushButtonMulticlick::attachDuringLongPress()
{
    traceme;
    OneButton::attachDuringLongPress(onDuringLongPress, this);
}