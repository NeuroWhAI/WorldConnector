#include "Point.h"




template <typename T>
PointT<T>::PointT()
	: m_x(T())
	, m_y(T())
{

}


template <typename T>
PointT<T>::~PointT()
{

}

//##########################################################################

template <typename T>
const T PointT<T>::getX() const
{
	return m_x;
}


template <typename T>
const T PointT<T>::getY() const
{
	return m_y;
}

//--------------------------------------------------------------------------

template <typename T>
void PointT<T>::setX(const T& x)
{
	m_x = x;
}


template <typename T>
void PointT<T>::setY(const T& y)
{
	m_y = y;
}


template <typename T>
void PointT<T>::setLocation(const T& x, const T& y)
{
	m_x = x;
	m_y = y;
}

//--------------------------------------------------------------------------

template <typename T>
void PointT<T>::moveX(const T& deltaX)
{
	m_x += deltaX;
}


template <typename T>
void PointT<T>::moveY(const T& deltaY)
{
	m_y += deltaY;
}


template <typename T>
void PointT<T>::move(const T& deltaX, const T& deltaY)
{
	m_x += deltaX;
	m_y += deltaY;
}

