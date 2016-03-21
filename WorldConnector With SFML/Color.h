#ifndef __SFML_WC__COLOR_H__
#define __SFML_WC__COLOR_H__


#include "WorldConnector\Color.h"




class Color : public WorldConnector::Drawing::Color
{
public:
	Color();
	virtual ~Color();


protected:
	int m_alpha, m_red, m_green, m_blue;


public:
	virtual char getA() const override;
	virtual char getR() const override;
	virtual char getG() const override;
	virtual char getB() const override;
	virtual int getArgb() const override;

	virtual void setA(int alpha) override;
	virtual void setR(int red) override;
	virtual void setG(int green) override;
	virtual void setB(int blue) override;
	virtual void setArgb(int argb) override;
	virtual void setArgb(int a, int r, int g, int b) override;
};


#endif