#ifndef PushButtonMulticlick_h
#define PushButtonMulticlick_h

#include "UnitConfiguration.h"
#include "OneButton.h"

class PushButtonMulticlick //: public Button
{
private:
	// Setup a new OneButton on pin PIN_INPUT
	// The 2. parameter activeLOW is true, because external wiring sets the button to LOW when pressed.
	OneButton _button;

public:
	// PushButtonMulticlick(uint8_t pin, uint8_t id = 0);
	virtual ~PushButtonMulticlick();
	// virtual StateChangedResult stateIsChanged() override;
};
#endif
