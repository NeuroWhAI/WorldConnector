#ifndef __WC__TEXTURE_H__
#define __WC__TEXTURE_H__


#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


template <typename T>
class RectangleT
{
public:
	RectangleT();
	virtual ~RectangleT();


public:
	virtual const T getX() const = 0;
	virtual const T getY() const = 0;
	virtual const T getWidth() const = 0;
	virtual const T getHeight() const = 0;

	virtual void setX(const T& x) = 0;
	virtual void setY(const T& y) = 0;
	virtual void setWidth(const T& width) = 0;
	virtual void setHeight(const T& height) = 0;
	virtual void setLocation(const T& x, const T& y) = 0;
	virtual void setSize(const T& width, const T& height) = 0;
	virtual void setRectangle(const T& x, const T& y,
		const T& width, const T& height) = 0;
};


using Rectangle = RectangleT<int>;
using RectangleF = RectangleT<float>;


END_WC_DRAWING_NAMESPACE


#include "Rectangle.inl"


#endif