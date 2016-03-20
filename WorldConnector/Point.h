#ifndef __WC__POINT_H__
#define __WC__POINT_H__


#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE



template <typename T>
class PointT
{
public:
	PointT();
	virtual ~PointT();


public:
	virtual const T getX() const = 0;
	virtual const T getY() const = 0;

	virtual void setX(const T& x) = 0;
	virtual void setY(const T& y) = 0;
	virtual void setLocation(const T& x, const T& y) = 0;
};


using PointF = PointT<float>;
using Point = PointT<int>;


END_WC_DRAWING_NAMESPACE


#include "Point.inl"


#endif