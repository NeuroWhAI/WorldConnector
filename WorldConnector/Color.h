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

	virtual void setA(int alpha) = 0;
	virtual void setR(int red) = 0;
	virtual void setG(int green) = 0;
	virtual void setB(int blue) = 0;
	virtual void setArgb(int argb) = 0;
	virtual void setArgb(int a, int r, int g, int b) = 0;
};


END_WC_DRAWING_NAMESPACE


#endif