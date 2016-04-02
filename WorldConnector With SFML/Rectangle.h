#ifndef __SFML_WC__RECTANGLE_H__
#define __SFML_WC__RECTANGLE_H__


#include "WorldConnector\Rectangle.h"

#include "WorldConnector\Point.h"
#include "WorldConnector\Size.h"




template <typename T>
class RectangleT : public WorldConnector::Drawing::RectangleT<T>
{
public:
	RectangleT();
	virtual ~RectangleT();


protected:
	T m_x, m_y, m_width, m_height;


public:
	virtual const T getX() const override;
	virtual const T getY() const override;
	virtual const T getWidth() const override;
	virtual const T getHeight() const override;

	virtual void setX(const T& x) override;
	virtual void setY(const T& y) override;
	virtual void setWidth(const T& width) override;
	virtual void setHeight(const T& height) override;
	virtual void setLocation(const T& x, const T& y) override;
	virtual void setSize(const T& width, const T& height) override;
	virtual void setRectangle(const T& x, const T& y,
		const T& width, const T& height) override;
};


using Rectangle = RectangleT<int>;
using RectangleF = RectangleT<float>;


#include "Rectangle.inl"


#endif