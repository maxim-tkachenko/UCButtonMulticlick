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
    _lastReadState = StateChangedResult(true, true, PushButtonMulticlickTriggerType::Single);
}

void PushButtonMulticlick::onDoubleClick()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, PushButtonMulticlickTriggerType::Double);
}

void PushButtonMulticlick::onMultiClick()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, getNumberClicks());
}

void PushButtonMulticlick::onLongPressStart()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, PushButtonMulticlickTriggerType::LongPressStart);
}

void PushButtonMulticlick::onLongPressStop()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, PushButtonMulticlickTriggerType::LongPressStop);
}

void PushButtonMulticlick::onDuringLongPress()
{
    traceme;
    _lastReadState = StateChangedResult(true, true, PushButtonMulticlickTriggerType::DuringLongPress);
}
