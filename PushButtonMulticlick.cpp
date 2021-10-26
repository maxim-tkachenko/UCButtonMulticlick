#include "PushButtonMulticlick.h"

PushButtonMulticlick::PushButtonMulticlick(
    uint8_t pin,
    // uint8_t clicks[],
    uint8_t id)
    : Button(pin, id),
      _button(pin, true),
      _lastReadState(false, false)
{
    traceme;

    _button.attachClick(__handleClick, this);
    _button.attachDoubleClick(__handleDoubleClick, this);
    _button.attachLongPressStop(__handleLongPressStop, this);
}

PushButtonMulticlick::~PushButtonMulticlick()
{
    traceme;
}

void PushButtonMulticlick::init()
{
    // setup interrupt routine
    // when not registering to the interrupt the sketch also works when the tick is called frequently.
    // attachInterrupt(digitalPinToInterrupt(pin), checkTicks, CHANGE);

    // for (auto i = 0; i < sizeof(clicks); i++)
    // {
    //     switch (clicks[i])
    //     {
    //     case 1:
    //         _button.attachClick(singleClick);
    //         break;

    //     default:
    //         break;
    //     }
    // }

    // link the xxxclick functions to be called on xxxclick event.
    // _button.attachClick(singleClick);
    // _button.attachDoubleClick(doubleClick);
    // _button.attachMultiClick(multiClick);

    // _button.setPressTicks(800); // that is the time when LongPressStart is called
    // button.attachLongPressStart(pressStart);
    // _button.attachLongPressStop(
    //     pressStop);
    // // []()
    // // {
    // //     Serial.println("Double Pressed!");
    // //     _button.tick();
    // // });

    return;

    _button.attachClick(__handleClick, this);
    _button.attachDoubleClick(__handleDoubleClick, this);
    _button.attachLongPressStop(__handleLongPressStop, this);
}

void PushButtonMulticlick::tick()
{
    // traceme;
    _button.tick();
}

/*// This function is called from the interrupt when the signal on the PIN_INPUT has changed.
// do not use Serial in here.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO_EVERY) || __AVR
static void PushButtonMulticlick::checkTicks()
{
    // include all buttons here to be checked
    _button.tick(); // just call tick() to check the state.
}

#elif defined(ESP8266)
ICACHE_RAM_ATTR static void PushButtonMulticlick::checkTicks()
{
    // include all buttons here to be checked
    button.tick(); // just call tick() to check the state.
}

#endif*/

/* ======================================

// this function will be called when the button was pressed 1 time only.
static void
PushButtonMulticlick::singleClick()
{
    Serial.println("singleClick() detected.");
} // singleClick

// this function will be called when the button was pressed 2 times in a short timeframe.
static void PushButtonMulticlick::doubleClick()
{
    Serial.println("doubleClick() detected.");

    // ledState = !ledState; // reverse the LED
    // digitalWrite(PIN_LED, ledState);
} // doubleClick

// this function will be called when the button was released after a long hold.
static void PushButtonMulticlick::pressStop()
{
    Serial.print("pressStop(");
    // Serial.print(millis() - pressStartTime);
    Serial.println(") detected.");
} // pressStop()

========================== */

// events
void PushButtonMulticlick::clickEvent()
{
    PlatformFeatures::println("singleClick() detected.");

    // auto isChanged = _
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

/*
// this function will be called when the button was pressed multiple times in a short timeframe.
void PushButtonMulticlick::multiClick()
{
    Serial.print("multiClick(");
    Serial.print(_button.getNumberClicks());
    Serial.println(") detected.");

    // ledState = !ledState; // reverse the LED
    // digitalWrite(PIN_LED, ledState);
} // multiClick

// this function will be called when the button was held down for 1 second or more.
void PushButtonMulticlick::pressStart()
{
    Serial.println("pressStart()");
    // pressStartTime = millis() - 1000; // as set in setPressTicks()
} // pressStart()*/
