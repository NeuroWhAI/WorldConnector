#include "Size.h"




template <typename T>
SizeT<T>::SizeT()
	: m_width(T())
	, m_height(T())
{

}


template <typename T>
SizeT<T>::~SizeT()
{

}

//##########################################################################

template <typename T>
const T SizeT<T>::getWidth() const
{
	return m_width;
}


template <typename T>
const T SizeT<T>::getHeight() const
{
	return m_height;
}

//--------------------------------------------------------------------------

template <typename T>
void SizeT<T>::setWidth(const T& width)
{
	m_width = width;
}


template <typename T>
void SizeT<T>::setHeight(const T& height)
{
	m_height = height;
}

