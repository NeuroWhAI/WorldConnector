#include "Graphics.h"




using Color = Graphics::Color;
using Font = Graphics::Font;
using Point = Graphics::Point;
using PointF = Graphics::PointF;
using Size = Graphics::Size;
using SizeF = Graphics::SizeF;

//###########################################################################

Graphics::Graphics()
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

}


void Graphics::endDrawRectangle()
{

}


void Graphics::drawRectangle(int x, int y, int width, int height, const Color& color)
{

}


void Graphics::drawRectangle(const Point& location, const Size& size, const Color& color)
{

}


void Graphics::drawRectangle(float x, float y, float width, float height, const Color& color)
{

}


void Graphics::drawRectangle(const PointF& location, const SizeF& size, const Color& color)
{

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

