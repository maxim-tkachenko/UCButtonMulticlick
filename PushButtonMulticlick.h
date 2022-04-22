#ifndef PushButtonMulticlick_h
#define PushButtonMulticlick_h

#include <UnitConfiguration.h> // revision #f24cf8e8a86ae83bc3522570ec41ef8c7317f777
#include <OneButton.h>		   // v2.0.2

enum PushButtonMulticlickTriggerType : uint8_t
{
	Single = 1,
	Double = 2,
	Triple = 3,
	// 4...252 values represent number of clicks
	LongPressStart = 253,
	LongPressStop = 254,
	DuringLongPress = 255,
};

class PushButtonMulticlick : public Button, public OneButton
{
private:
	static void onClick(void *sender)
	{
		traceme;
		_setLastReadState(sender, PushButtonMulticlickTriggerType::Single);
	}

	static void onDoubleClick(void *sender)
	{
		traceme;
		_setLastReadState(sender, PushButtonMulticlickTriggerType::Double);
	}

	static void onMultiClick(void *sender)
	{
		traceme;
		_setLastReadState(sender, ((PushButtonMulticlick *)sender)->getNumberClicks());
	}

	static void onLongPressStart(void *sender)
	{
		traceme;
		_setLastReadState(sender, PushButtonMulticlickTriggerType::LongPressStart);
	}

	static void onLongPressStop(void *sender)
	{
		traceme;
		_setLastReadState(sender, PushButtonMulticlickTriggerType::LongPressStop);
	}

	static void onDuringLongPress(void *sender)
	{
		traceme;
		_setLastReadState(sender, PushButtonMulticlickTriggerType::DuringLongPress);
	}

	static void _setLastReadState(void *sender, uint8_t stateCode)
	{
		((PushButtonMulticlick *)sender)->setLastReadState(stateCode);
	}

protected:
	StateChangedResult _lastReadState;
	void setLastReadState(uint8_t stateCode);

	virtual void init() override;

public:
	PushButtonMulticlick(uint8_t pin, uint8_t id = 0);
	virtual ~PushButtonMulticlick();
	virtual StateChangedResult stateIsChanged() override;
	void tick() override;

	void attachClick();
	void attachDoubleClick();
	void attachMultiClick();
	void attachLongPressStart();
	void attachLongPressStop();
	void attachDuringLongPress();
};

#endif
