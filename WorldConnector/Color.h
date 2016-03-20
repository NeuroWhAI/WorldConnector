#ifndef __WC__COLOR_H__
#define __WC__COLOR_H__


#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


class Color
{
public:
	Color();
	virtual ~Color();


public:
	virtual char getA() const = 0;
	virtual char getR() const = 0;
	virtual char getG() const = 0;
	virtual char getB() const = 0;
	virtual int getArgb() const = 0;

	virtual void setA(char alpha) = 0;
	virtual void setR(char red) = 0;
	virtual void setG(char green) = 0;
	virtual void setB(char blue) = 0;
	virtual void setArgb(int argb) = 0;
	virtual void setArgb(char a, char r, char g, char b) = 0;
};


END_WC_DRAWING_NAMESPACE


#endif