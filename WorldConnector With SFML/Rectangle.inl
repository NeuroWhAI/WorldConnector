#include "Rectangle.h"




template <typename T>
RectangleT<T>::RectangleT()
	: m_x(T())
	, m_y(T())
	, m_width(T())
	, m_height(T())
{

}


template <typename T>
RectangleT<T>::~RectangleT()
{

}

//############################################################################

template <typename T>
const T RectangleT<T>::getX() const
{
	return m_x;
}


template <typename T>
const T RectangleT<T>::getY() const
{
	return m_y;
}


template <typename T>
const T RectangleT<T>::getWidth() const
{
	return m_width;
}


template <typename T>
const T RectangleT<T>::getHeight() const
{
	return m_height;
}

//--------------------------------------------------------------------------

template <typename T>
void RectangleT<T>::setX(const T& x)
{
	m_x = x;
}


template <typename T>
void RectangleT<T>::setY(const T& y)
{
	m_y = y;
}


template <typename T>
void RectangleT<T>::setWidth(const T& width)
{
	m_width = width;
}


template <typename T>
void RectangleT<T>::setHeight(const T& height)
{
	m_height = height;
}


template <typename T>
void RectangleT<T>::setLocation(const T& x, const T& y)
{
	m_x = x;
	m_y = y;
}


template <typename T>
void RectangleT<T>::setSize(const T& width, const T& height)
{
	m_x = width;
	m_y = height;
}


template <typename T>
void RectangleT<T>::setRectangle(const T& x, const T& y,
	const T& width, const T& height)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
}

