#ifndef PushButtonMulticlick_h
#define PushButtonMulticlick_h

#include <UnitConfiguration.h> // revision #f24cf8e8a86ae83bc3522570ec41ef8c7317f777
#include <OneButton.h>

class PushButtonMulticlick : public Button, public OneButton
{
private:
	StateChangedResult _lastReadState;

protected:
	virtual void init() override;

public:
	PushButtonMulticlick(uint8_t pin, uint8_t id = 0);
	virtual ~PushButtonMulticlick();
	virtual StateChangedResult stateIsChanged() override;
	void tick() override;

	// event handlers
	void onClick();
	void onDoubleClick();
	void onMultiClick();
	void onLongPressStart();
	void onLongPressStop();
	void onDuringLongPress();
};

enum PushButtonMulticlickTriggerType : uint8_t
{
	Single = 1,
	Double = 2,
	Multi = 3,
	LongPressStart = 4,
	LongPressStop = 5,
	DuringLongPress = 6,
};

// Handler wrapper function for a single click:
static void __onPushButtonMulticlickClicked(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->onClick();
}

// Handler wrapper function for a double click:
static void __onPushButtonMulticlickDoubleClicked(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->onDoubleClick();
}

// Handler wrapper function for a multi click:
static void __onPushButtonMulticlickMulticlicked(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->onMultiClick();
}

// Handler wrapper function for a long press start:
static void __onPushButtonMulticlickLongPressStarted(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->onLongPressStart();
}

// Handler wrapper function for a long press stop:
static void __onPushButtonMulticlickLongPressStopped(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->onLongPressStop();
}

// Handler wrapper function for a during long press:
static void __onPushButtonMulticlickDuringLongPressed(void *s)
{
	traceme;
	((PushButtonMulticlick *)s)->onDuringLongPress();
}

#endif
