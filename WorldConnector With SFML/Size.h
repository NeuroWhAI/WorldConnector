#ifndef __SFML_WC__SIZE_H__
#define __SFML_WC__SIZE_H__


#include "WorldConnector\Size.h"




template <typename T>
class SizeT : public WorldConnector::Drawing::SizeT<T>
{
public:
	SizeT();
	virtual ~SizeT();


protected:
	T m_width, m_height;


public:
	virtual const T getWidth() const override;
	virtual const T getHeight() const override;

	virtual void setWidth(const T& width) override;
	virtual void setHeight(const T& height) override;
};


using Size = SizeT<int>;
using SizeF = SizeT<float>;


#include "Size.inl"


#endif