#ifndef __SFML_WC__POINT_H__
#define __SFML_WC__POINT_H__


#include "WorldConnector\Point.h"




template <typename T>
class PointT : public WorldConnector::Drawing::PointT<T>
{
public:
	PointT();
	virtual ~PointT();


protected:
	T m_x, m_y;


public:
	virtual const T getX() const override;
	virtual const T getY() const override;

	virtual void setX(const T& x) override;
	virtual void setY(const T& y) override;
	virtual void setLocation(const T& x, const T& y) override;

	virtual void moveX(const T& deltaX) override;
	virtual void moveY(const T& deltaY) override;
	virtual void move(const T& deltaX, const T& deltaY) override;
};


using Point = PointT<int>;
using PointF = PointT<float>;


#include "Point.inl"


#endif