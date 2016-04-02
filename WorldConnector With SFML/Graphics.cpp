#include "Graphics.h"

#include "Color.h"
#include "Font.h"
#include "Point.h"
#include "Size.h"
#include "Rectangle.h"




Graphics::Graphics(sf::RenderWindow& window)
	: m_win(window)

	, m_transform(sf::Transform::Identity)
	, m_renderStates(sf::RenderStates::Default)
{

}


Graphics::~Graphics()
{

}

//###########################################################################

sf::Color Graphics::convertToSFML(const Color& color) const
{
	return sf::Color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA());
}


sf::Vector2f Graphics::convertToSFML(const Point& location) const
{
	return sf::Vector2f(static_cast<float>(location.getX()),
		static_cast<float>(location.getY()));
}


sf::Vector2f Graphics::convertToSFML(const PointF& location) const
{
	return sf::Vector2f(location.getX(),
		location.getY());
}


sf::Vector2f Graphics::convertToSFML(const Size& size) const
{
	return sf::Vector2f(static_cast<float>(size.getWidth()),
		static_cast<float>(size.getHeight()));
}


sf::Vector2f Graphics::convertToSFML(const SizeF& size) const
{
	return sf::Vector2f(size.getWidth(),
		size.getHeight());
}

//###########################################################################

void Graphics::resetTransform()
{
	m_transform = sf::Transform::Identity;

	m_renderStates.transform = m_transform;
}


void Graphics::translate(int x, int y)
{
	m_transform.translate(static_cast<float>(x), static_cast<float>(y));

	m_renderStates.transform = m_transform;
}


void Graphics::translate(float x, float y)
{
	m_transform.translate(x, y);

	m_renderStates.transform = m_transform;
}


void Graphics::rotate(float degree)
{
	m_transform.rotate(degree);

	m_renderStates.transform = m_transform;
}


void Graphics::scale(float x, float y)
{
	m_transform.scale(x, y);

	m_renderStates.transform = m_transform;
}

//###########################################################################

void Graphics::beginDrawLine(float thickness)
{

}


void Graphics::endDrawLine()
{

}


void Graphics::drawLine(int x1, int y1, int x2, int y2, const Color& color)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].color = convertToSFML(color);
	line[0].position = sf::Vector2f(static_cast<float>(x1),
		static_cast<float>(y1));
	line[1].color = convertToSFML(color);
	line[1].position = sf::Vector2f(static_cast<float>(x2),
		static_cast<float>(y2));

	m_win.draw(line, m_renderStates);
}


void Graphics::drawLine(const Point& point1, const Point& point2, const Color& color)
{
	drawLine(point1.getX(), point1.getY(),
		point2.getX(), point2.getY(),
		color);
}


void Graphics::drawLine(const Point* vertexArray[], std::size_t vertexCount, const Color& color, bool closed)
{
	sf::VertexArray vertexList(closed ? sf::LinesStrip : sf::Lines,
		vertexCount);

	sf::Color sfColor = convertToSFML(color);

	for (std::size_t i = 0; i < vertexCount; ++i)
	{
		vertexList[i].color = sfColor;
		vertexList[i].position = convertToSFML(*vertexArray[i]);
	}

	m_win.draw(vertexList, m_renderStates);
}


void Graphics::drawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].color = convertToSFML(color);
	line[0].position = sf::Vector2f(x1, y1);
	line[1].color = convertToSFML(color);
	line[1].position = sf::Vector2f(x2, y2);

	m_win.draw(line, m_renderStates);
}


void Graphics::drawLine(const PointF& point1, const PointF& point2, const Color& color)
{
	drawLine(point1.getX(), point1.getY(),
		point2.getX(), point2.getY(),
		color);
}


void Graphics::drawLine(const PointF* vertexArray[], std::size_t vertexCount, const Color& color, bool closed)
{
	sf::VertexArray vertexList(closed ? sf::LinesStrip : sf::Lines,
		vertexCount);

	sf::Color sfColor = convertToSFML(color);

	for (std::size_t i = 0; i < vertexCount; ++i)
	{
		vertexList[i].color = sfColor;
		vertexList[i].position = convertToSFML(*vertexArray[i]);
	}

	m_win.draw(vertexList, m_renderStates);
}

//--------------------------------------------------------------------------

void Graphics::beginDrawRectangle(float thickness)
{
	m_drawRect.setOutlineThickness(thickness);
	m_drawRect.setFillColor(sf::Color::Transparent);
}


void Graphics::endDrawRectangle()
{
	m_drawRect.setOutlineThickness(1.0f);
	m_drawRect.setFillColor(sf::Color::White);
}


void Graphics::drawRectangle(int x, int y, int width, int height, const Color& color)
{
	m_drawRect.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_drawRect.setSize(sf::Vector2f(static_cast<float>(width),
		static_cast<float>(height)));
	m_drawRect.setOutlineColor(convertToSFML(color));

	m_win.draw(m_drawRect, m_renderStates);
}


void Graphics::drawRectangle(const Point& location, const Size& size, const Color& color)
{
	drawRectangle(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(),
		color);
}


void Graphics::drawRectangle(const Rectangle& rectangle, const Color& color)
{
	drawRectangle(rectangle.getX(), rectangle.getY(),
		rectangle.getWidth(), rectangle.getHeight(),
		color);
}


void Graphics::drawRectangle(float x, float y, float width, float height, const Color& color)
{
	m_drawRect.setPosition(x, y);
	m_drawRect.setSize(sf::Vector2f(width, height));
	m_drawRect.setOutlineColor(convertToSFML(color));

	m_win.draw(m_drawRect, m_renderStates);
}


void Graphics::drawRectangle(const PointF& location, const SizeF& size, const Color& color)
{
	drawRectangle(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(),
		color);
}


void Graphics::drawRectangle(const RectangleF& rectangle, const Color& color)
{
	drawRectangle(rectangle.getX(), rectangle.getY(),
		rectangle.getWidth(), rectangle.getHeight(),
		color);
}

//--------------------------------------------------------------------------

void Graphics::beginFillRectangle()
{
	// empty
}


void Graphics::endFillRectangle()
{
	// empty
}


void Graphics::fillRectangle(int x, int y, int width, int height, const Color& color)
{
	m_fillRect.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_fillRect.setSize(sf::Vector2f(static_cast<float>(width),
		static_cast<float>(height)));
	m_fillRect.setFillColor(convertToSFML(color));

	m_win.draw(m_fillRect, m_renderStates);
}


void Graphics::fillRectangle(const Point& location, const Size& size, const Color& color)
{
	fillRectangle(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(),
		color);
}


void Graphics::fillRectangle(const Rectangle& rectangle, const Color& color)
{
	fillRectangle(rectangle.getX(), rectangle.getY(),
		rectangle.getWidth(), rectangle.getHeight(),
		color);
}


void Graphics::fillRectangle(float x, float y, float width, float height, const Color& color)
{
	m_fillRect.setPosition(x, y);
	m_fillRect.setSize(sf::Vector2f(width, height));
	m_fillRect.setFillColor(convertToSFML(color));

	m_win.draw(m_fillRect, m_renderStates);
}


void Graphics::fillRectangle(const PointF& location, const SizeF& size, const Color& color)
{
	fillRectangle(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(),
		color);
}


void Graphics::fillRectangle(const RectangleF& rectangle, const Color& color)
{
	fillRectangle(rectangle.getX(), rectangle.getY(),
		rectangle.getWidth(), rectangle.getHeight(),
		color);
}

//--------------------------------------------------------------------------

void Graphics::beginDrawEllipse(float thickness)
{
	m_drawCircle.setOutlineThickness(thickness);
	m_drawCircle.setFillColor(sf::Color::Transparent);
}


void Graphics::endDrawEllipse()
{
	m_drawCircle.setOutlineThickness(1.0f);
	m_drawCircle.setFillColor(sf::Color::White);
}


void Graphics::drawEllipse(int x, int y, int width, int height, const Color& color)
{
	m_drawCircle.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_drawCircle.setRadius(width / 2.0f);
	m_drawCircle.setScale(1.0f, static_cast<float>(height) / width);
	m_drawCircle.setOutlineColor(convertToSFML(color));

	m_win.draw(m_drawCircle, m_renderStates);
}


void Graphics::drawEllipse(const Point& location, const Size& size, const Color& color)
{
	drawEllipse(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(), color);
}


void Graphics::drawEllipse(float x, float y, float width, float height, const Color& color)
{
	m_drawCircle.setPosition(x, y);
	m_drawCircle.setRadius(width / 2.0f);
	m_drawCircle.setScale(1.0f, height / width);
	m_drawCircle.setOutlineColor(convertToSFML(color));

	m_win.draw(m_drawCircle, m_renderStates);
}


void Graphics::drawEllipse(const PointF& location, const SizeF& size, const Color& color)
{
	drawEllipse(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(), color);
}

//--------------------------------------------------------------------------

void Graphics::beginFillEllipse()
{
	// empty
}


void Graphics::endFillEllipse()
{
	// empty
}


void Graphics::fillEllipse(int x, int y, int width, int height, const Color& color)
{
	m_fillCircle.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_fillCircle.setRadius(width / 2.0f);
	m_fillCircle.setScale(1.0f, static_cast<float>(height) / width);
	m_fillCircle.setFillColor(convertToSFML(color));

	m_win.draw(m_fillCircle, m_renderStates);
}


void Graphics::fillEllipse(const Point& location, const Size& size, const Color& color)
{
	fillEllipse(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(), color);
}


void Graphics::fillEllipse(float x, float y, float width, float height, const Color& color)
{
	m_fillCircle.setPosition(x, y);
	m_fillCircle.setRadius(width / 2.0f);
	m_fillCircle.setScale(1.0f, height / width);
	m_fillCircle.setFillColor(convertToSFML(color));

	m_win.draw(m_fillCircle, m_renderStates);
}


void Graphics::fillEllipse(const PointF& location, const SizeF& size, const Color& color)
{
	fillEllipse(location.getX(), location.getY(),
		size.getWidth(), size.getHeight(), color);
}

//--------------------------------------------------------------------------

void Graphics::beginDrawString(const Font& font, const Color& color)
{
	auto findFont = m_fontMap.find(font.getName());
	if (findFont == m_fontMap.end())
	{
		m_currentFont.loadFromFile(font.getName());
		m_fontMap.insert(std::make_pair(font.getName(), m_currentFont));
	}
	else
	{
		m_currentFont = findFont->second;
	}

	m_text.setFont(m_currentFont);
	m_text.setColor(convertToSFML(color));
	m_text.setCharacterSize(font.getHeight());

	int style = sf::Text::Regular;
	if (font.hasBoldStyle())
		style |= sf::Text::Bold;
	if (font.hasItalicStyle())
		style |= sf::Text::Italic;
	if (font.hasStrikeOutStyle())
		style |= sf::Text::StrikeThrough;
	if (font.hasUnderlineStyle())
		style |= sf::Text::Underlined;
	m_text.setStyle(style);
}


void Graphics::endDrawString()
{
	m_text.setString("");
	m_text.setColor(sf::Color::Black);
	m_text.setCharacterSize(30);
	m_text.setStyle(sf::Text::Regular);
}


void Graphics::drawString(const std::string& text, int x, int y)
{
	m_text.setString(text);
	m_text.setPosition(static_cast<float>(x), static_cast<float>(y));

	m_win.draw(m_text, m_renderStates);
}


void Graphics::drawString(const std::string& text, const Point& location)
{
	drawString(text, location.getX(), location.getY());
}


void Graphics::drawString(const std::string& text, float x, float y)
{
	m_text.setString(text);
	m_text.setPosition(x, y);

	m_win.draw(m_text, m_renderStates);
}


void Graphics::drawString(const std::string& text, const PointF& location)
{
	drawString(text, location.getX(), location.getY());
}


void Graphics::drawString(const std::wstring& text, int x, int y)
{
	m_text.setString(text);
	m_text.setPosition(static_cast<float>(x), static_cast<float>(y));

	m_win.draw(m_text, m_renderStates);
}


void Graphics::drawString(const std::wstring& text, const Point& location)
{
	drawString(text, location.getX(), location.getY());
}


void Graphics::drawString(const std::wstring& text, float x, float y)
{
	m_text.setString(text);
	m_text.setPosition(x, y);

	m_win.draw(m_text, m_renderStates);
}


void Graphics::drawString(const std::wstring& text, const PointF& location)
{
	drawString(text, location.getX(), location.getY());
}

