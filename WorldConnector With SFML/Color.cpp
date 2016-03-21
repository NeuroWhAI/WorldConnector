#include "Color.h"




Color::Color()
	: m_alpha(0)
	, m_red(0)
	, m_green(0)
	, m_blue(0)
{

}


Color::~Color()
{

}

//###########################################################################

char Color::getA() const
{
	return m_alpha;
}


char Color::getR() const
{
	return m_red;
}


char Color::getG() const
{
	return m_green;
}


char Color::getB() const
{
	return m_blue;
}


int Color::getArgb() const
{
	return (((m_alpha & 0x000000ff) << 24)
		|| ((m_red & 0x000000ff) << 16)
		|| ((m_green & 0x000000ff) << 8)
		|| ((m_blue & 0x000000ff)));
}

//--------------------------------------------------------------------------

void Color::setA(int alpha)
{
	m_alpha = alpha;
}


void Color::setR(int red)
{
	m_red = red;
}


void Color::setG(int green)
{
	m_green = green;
}


void Color::setB(int blue)
{
	m_blue = blue;
}


void Color::setArgb(int argb)
{
	m_alpha = ((argb & 0xff000000) >> 24);
	m_red = ((argb & 0x00ff0000) >> 16);
	m_green = ((argb & 0x0000ff00) >> 8);
	m_blue = (argb & 0x000000ff);
}


void Color::setArgb(int a, int r, int g, int b)
{
	m_alpha = a;
	m_red = r;
	m_green = g;
	m_blue = b;
}

