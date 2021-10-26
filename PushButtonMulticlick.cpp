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

StateChangedResult PushButtonMulticlick::stateIsChanged()
{
    auto s = _lastReadState;
    _lastReadState = StateChangedResult(false, false);

    return s;
}

// event handlers
void PushButtonMulticlick::onClick()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, 1);
}

void PushButtonMulticlick::onDoubleClick()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, 2);
}

void PushButtonMulticlick::onMultiClick()
{
    traceme;
}

void PushButtonMulticlick::onLongPressStart()
{
    traceme;
}

void PushButtonMulticlick::onLongPressStop()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, 3);
}

void PushButtonMulticlick::onDuringLongPress()
{
    traceme;
}
