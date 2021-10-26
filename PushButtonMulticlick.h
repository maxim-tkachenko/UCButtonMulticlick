#ifndef PushButtonMulticlick_h
#define PushButtonMulticlick_h

#include <UnitConfiguration.h> // revision #f24cf8e8a86ae83bc3522570ec41ef8c7317f777
#include <OneButton.h>

class PushButtonMulticlick : public Button
{
private:
	// Setup a new OneButton on pin PIN_INPUT
	// The 2. parameter activeLOW is true, because external wiring sets the button to LOW when pressed.
	OneButton _button;
	StateChangedResult _lastReadState;

protected:
	virtual void init() override;

public:
	PushButtonMulticlick(uint8_t pin, /*uint8_t clicks[],*/ uint8_t id = 0);
	virtual ~PushButtonMulticlick();
	virtual StateChangedResult stateIsChanged() override;
	void tick() override;

	// events
	void clickEvent();
	void pressEvent();
	void longPressStartEvent();
	void longPressStopEvent();
	void duringLongPressEvent();
	void doubleClickEvent();
};

// enum
// {
// 	fff,
// } PushButtonMulticlickResult;

// Handler wrapper function for a single click:
static void __handleClick(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->clickEvent();
}

// Handler wrapper function for a double click:
static void __handleDoubleClick(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->doubleClickEvent();
}

// Handler wrapper function for a long press start :
static void __handleLongPressStart(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->longPressStartEvent();
}

// Handler wrapper function for a long press stop:
static void __handleLongPressStop(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->longPressStopEvent();
}

// Handler wrapper function for a during long press:
static void __handleDuringLongPress(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->duringLongPressEvent();
}

#endif
