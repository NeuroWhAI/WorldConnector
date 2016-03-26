#ifndef __SFML_WC__GRAPHICS_H__
#define __SFML_WC__GRAPHICS_H__


#include "WorldConnector\Graphics.h"

#include "SFML\Graphics.hpp"




class Graphics : public WorldConnector::Drawing::Graphics
{
public:
	using Color = WorldConnector::Drawing::Color;
	using Font = WorldConnector::Drawing::Font;
	using Point = WorldConnector::Drawing::Point;
	using PointF = WorldConnector::Drawing::PointF;
	using Size = WorldConnector::Drawing::Size;
	using SizeF = WorldConnector::Drawing::SizeF;


public:
	explicit Graphics(sf::RenderWindow& window);
	virtual ~Graphics();


protected:
	sf::RenderWindow& m_win;


protected:
	sf::RectangleShape m_rectangle;


public:
	virtual void beginDrawLine(float thickness) override;
	virtual void endDrawLine() override;
	virtual void drawLine(int x1, int y1, int x2, int y2, const Color& color) override;
	virtual void drawLine(const Point& point1, const Point& point2, const Color& color) override;
	virtual void drawLine(float x1, float y1, float x2, float y2, const Color& color) override;
	virtual void drawLine(const PointF& point1, const PointF& point2, const Color& color) override;

	virtual void beginDrawRectangle(float thickness) override;
	virtual void endDrawRectangle() override;
	virtual void drawRectangle(int x, int y, int width, int height, const Color& color) override;
	virtual void drawRectangle(const Point& location, const Size& size, const Color& color) override;
	virtual void drawRectangle(float x, float y, float width, float height, const Color& color) override;
	virtual void drawRectangle(const PointF& location, const SizeF& size, const Color& color) override;

	virtual void beginFillRectangle() override;
	virtual void endFillRectangle() override;
	virtual void fillRectangle(int x, int y, int width, int height, const Color& color) override;
	virtual void fillRectangle(const Point& location, const Size& size, const Color& color) override;
	virtual void fillRectangle(float x, float y, float width, float height, const Color& color) override;
	virtual void fillRectangle(const PointF& location, const SizeF& size, const Color& color) override;

	virtual void beginDrawString(const Font& font, const Color& color) override;
	virtual void endDrawString() override;
	virtual void drawString(const std::string& text, int x, int y) override;
	virtual void drawString(const std::string& text, const Point& location) override;
	virtual void drawString(const std::string& text, float x, float y) override;
	virtual void drawString(const std::string& text, const PointF& location) override;
	virtual void drawString(const std::wstring& text, int x, int y) override;
	virtual void drawString(const std::wstring& text, const Point& location) override;
	virtual void drawString(const std::wstring& text, float x, float y) override;
	virtual void drawString(const std::wstring& text, const PointF& location) override;
};


#endif