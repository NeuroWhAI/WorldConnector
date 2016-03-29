#ifndef __WC__KEYBOARD_H__
#define __WC__KEYBOARD_H__


#include <memory>

#include "WCUtility.h"




BEGIN_WC_FORM_NAMESPACE


enum class Keys
{
	Unknown = -1,
	A = 0,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Num0,
	Num1,
	Num2,
	Num3,
	Num4,
	Num5,
	Num6,
	Num7,
	Num8,
	Num9,
	Escape,
	LControl,
	LShift,
	LAlt,
	LSystem,
	RControl,
	RShift,
	RAlt,
	RSystem,
	Menu,
	LBracket, // [
	RBracket, // ]
	SemiColon,
	Comma,
	Period, // .
	Quote, // '
	Slash,
	BackSlash,
	Tilde, // ~
	Equal,
	Dash, // -
	Space,
	Return,
	BackSpace,
	Tab,
	PageUp,
	PageDown,
	End,
	Home,
	Insert,
	Delete,
	Add,
	Subtract,
	Multiply,
	Divide,
	Left,
	Right,
	Up,
	Down,

	//------------------------
	Count,
};


class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard();


private:
	static std::shared_ptr<Keyboard> s_pInstance;

	class CleanUp
	{
	public:
		virtual ~CleanUp()
		{
			if (s_pInstance)
			{
				s_pInstance.reset();
			}
		}
	};

	static CleanUp s_cleaner;


public:
	static Keyboard* getInstance();


public:
	virtual void update() = 0;


public:
	virtual bool isKeyDown(Keys key) const = 0;
	virtual bool isKeyPressed(Keys key) const = 0;
	virtual bool isKeyUp(Keys key) const = 0;
};


END_WC_FORM_NAMESPACE


#endif