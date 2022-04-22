#include "PushButtonMulticlick.h"

PushButtonMulticlick::PushButtonMulticlick(
    uint8_t pin,
    uint8_t id)
    : Button(pin, id),
      OneButton(pin, true), // connects to digital pin and GND, which is active low and uses the internal pull-up resistor.
      lastReadState(false, false)
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

StateChangedResult PushButtonMulticlick::stateIsChanged()
{
    auto state = lastReadState;
    lastReadState = StateChangedResult(false, false);

    return state;
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