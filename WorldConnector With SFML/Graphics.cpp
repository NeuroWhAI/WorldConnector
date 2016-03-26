#include "Graphics.h"

#include "Color.h"
#include "Point.h"
#include "Size.h"




Graphics::Graphics(sf::RenderWindow& window)
	: m_win(window)
{

}


Graphics::~Graphics()
{

}

//###########################################################################

void Graphics::Graphics::beginDrawLine(float thickness)
{

}


void Graphics::Graphics::endDrawLine()
{

}


void Graphics::Graphics::drawLine(int x1, int y1, int x2, int y2, const Color& color)
{

}


void Graphics::Graphics::drawLine(const Point& point1, const Point& point2, const Color& color)
{

}


void Graphics::Graphics::drawLine(float x1, float y1, float x2, float y2, const Color& color)
{

}


void Graphics::Graphics::drawLine(const PointF& point1, const PointF& point2, const Color& color)
{

}

//--------------------------------------------------------------------------

void Graphics::beginDrawRectangle(float thickness)
{
	m_rectangle.setOutlineThickness(thickness);
	m_rectangle.setFillColor(sf::Color::Transparent);
}


void Graphics::endDrawRectangle()
{
	m_rectangle.setOutlineThickness(1.0f);
	m_rectangle.setFillColor(sf::Color::White);
}


void Graphics::drawRectangle(int x, int y, int width, int height, const Color& color)
{
	m_rectangle.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_rectangle.setSize(sf::Vector2f(static_cast<float>(width),
		static_cast<float>(height)));
	m_rectangle.setOutlineColor(sf::Color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA()));

	m_win.draw(m_rectangle);
}


void Graphics::drawRectangle(const Point& location, const Size& size, const Color& color)
{
	m_rectangle.setPosition(static_cast<float>(location.getX()),
		static_cast<float>(location.getY()));
	m_rectangle.setSize(sf::Vector2f(static_cast<float>(size.getWidth()),
		static_cast<float>(size.getHeight())));
	m_rectangle.setOutlineColor(sf::Color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA()));

	m_win.draw(m_rectangle);
}


void Graphics::drawRectangle(float x, float y, float width, float height, const Color& color)
{
	m_rectangle.setPosition(x, y);
	m_rectangle.setSize(sf::Vector2f(width, height));
	m_rectangle.setOutlineColor(sf::Color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA()));

	m_win.draw(m_rectangle);
}


void Graphics::drawRectangle(const PointF& location, const SizeF& size, const Color& color)
{
	m_rectangle.setPosition(location.getX(), location.getY());
	m_rectangle.setSize(sf::Vector2f(size.getWidth(), size.getHeight()));
	m_rectangle.setOutlineColor(sf::Color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA()));

	m_win.draw(m_rectangle);
}

//--------------------------------------------------------------------------

void Graphics::beginFillRectangle()
{

}


void Graphics::endFillRectangle()
{

}


void Graphics::fillRectangle(int x, int y, int width, int height, const Color& color)
{

}


void Graphics::fillRectangle(const Point& location, const Size& size, const Color& color)
{

}


void Graphics::fillRectangle(float x, float y, float width, float height, const Color& color)
{

}


void Graphics::fillRectangle(const PointF& location, const SizeF& size, const Color& color)
{

}

//--------------------------------------------------------------------------

void Graphics::beginDrawString(const Font& font, const Color& color)
{

}


void Graphics::endDrawString()
{

}


void Graphics::drawString(const std::string& text, int x, int y)
{

}


void Graphics::drawString(const std::string& text, const Point& location)
{

}


void Graphics::drawString(const std::string& text, float x, float y)
{

}


void Graphics::drawString(const std::string& text, const PointF& location)
{

}


void Graphics::drawString(const std::wstring& text, int x, int y)
{

}


void Graphics::drawString(const std::wstring& text, const Point& location)
{

}


void Graphics::drawString(const std::wstring& text, float x, float y)
{

}


void Graphics::drawString(const std::wstring& text, const PointF& location)
{

}

