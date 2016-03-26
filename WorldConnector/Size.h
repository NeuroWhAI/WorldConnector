#ifndef __WC__SIZE_H__
#define __WC__SIZE_H__


#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


template <typename T>
class SizeT
{
public:
	SizeT();
	virtual ~SizeT();


public:
	virtual const T getWidth() const = 0;
	virtual const T getHeight() const = 0;

	virtual void setWidth(const T& width) = 0;
	virtual void setHeight(const T& height) = 0;
	virtual void setSize(const T& width, const T& height) = 0;
};


using Size = SizeT<int>;
using SizeF = SizeT<float>;


END_WC_DRAWING_NAMESPACE


#include "Size.inl"


#endif