#ifndef __WC__EVENT_H__
#define __WC__EVENT_H__


#include "WCUtility.h"




BEGIN_WC_FORM_NAMESPACE


class Event
{
public:
	Event();
	virtual ~Event();


public:
	enum Types
	{
		Unknown = -1,
		Opened = 0,
		Closed,
		Resized,
		KeyDown,
		KeyUp,
		TouchBegan,
		TouchMoved,
		TouchEnded,
		Scrolled,

		//-------------
		Count
	};


protected:
	struct SizeEvent
	{
		int width, height;
	};

	struct KeyEvent
	{
		/*Keyboard::Keys*/int code;
	};

	struct TouchEvent
	{
		int x, y;
	};

	struct ScrollEvent
	{
		float delta;
	};

	
public:
	virtual Types getType() const = 0;
	virtual void setType(Types type) = 0;


public:
	union
	{
		SizeEvent size;
		KeyEvent key;
		TouchEvent touch;
		ScrollEvent scroll;
	};
};


END_WC_FORM_NAMESPACE


#endif