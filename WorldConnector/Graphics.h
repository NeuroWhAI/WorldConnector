#ifndef __WC__GRAPHICS_H__
#define __WC__GRAPHICS_H__


#include <string>

#include "WCUtility.h"

#include "Color.h"
#include "Font.h"
#include "Point.h"
#include "Size.h"




BEGIN_WC_DRAWING_NAMESPACE


class Graphics
{
public:
	Graphics();
	virtual ~Graphics();


public:
	virtual void beginDrawLine(float thickness) = 0;
	virtual void endDrawLine() = 0;
	virtual void drawLine(int x1, int y1, int x2, int y2, const Color& color) = 0;
	virtual void drawLine(const Point& point1, const Point& point2, const Color& color) = 0;
	virtual void drawLine(float x1, float y1, float x2, float y2, const Color& color) = 0;
	virtual void drawLine(const PointF& point1, const PointF& point2, const Color& color) = 0;

	virtual void beginDrawRectangle(float thickness) = 0;
	virtual void endDrawRectangle() = 0;
	virtual void drawRectangle(int x, int y, int width, int height, const Color& color) = 0;
	virtual void drawRectangle(const Point& location, const Size& size, const Color& color) = 0;
	virtual void drawRectangle(float x, float y, float width, float height, const Color& color) = 0;
	virtual void drawRectangle(const PointF& location, const SizeF& size, const Color& color) = 0;

	virtual void beginFillRectangle() = 0;
	virtual void endFillRectangle() = 0;
	virtual void fillRectangle(int x, int y, int width, int height, const Color& color) = 0;
	virtual void fillRectangle(const Point& location, const Size& size, const Color& color) = 0;
	virtual void fillRectangle(float x, float y, float width, float height, const Color& color) = 0;
	virtual void fillRectangle(const PointF& location, const SizeF& size, const Color& color) = 0;

	virtual void beginDrawString(const Font& font, const Color& color) = 0;
	virtual void endDrawString() = 0;
	virtual void drawString(const std::string& text, int x, int y) = 0;
	virtual void drawString(const std::string& text, const Point& location) = 0;
	virtual void drawString(const std::string& text, float x, float y) = 0;
	virtual void drawString(const std::string& text, const PointF& location) = 0;
	virtual void drawString(const std::wstring& text, int x, int y) = 0;
	virtual void drawString(const std::wstring& text, const Point& location) = 0;
	virtual void drawString(const std::wstring& text, float x, float y) = 0;
	virtual void drawString(const std::wstring& text, const PointF& location) = 0;
};


END_WC_DRAWING_NAMESPACE


#endif