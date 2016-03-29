#include "Factory.h"

#include "SFML\Graphics.hpp"

#include "Graphics.h"
#include "Color.h"
#include "Font.h"
#include "Point.h"
#include "Size.h"

#include "Window.h"
#include "Event.h"
#include "Keyboard.h"
#include "Touch.h"




Factory::Factory()
	: m_pWindow(nullptr)
{

}


Factory::~Factory()
{

}

//###########################################################################

std::shared_ptr<WorldConnector::Drawing::Graphics> Factory::createGraphics()
{
	return std::make_shared<Graphics>(*m_pWindow);
}


std::shared_ptr<WorldConnector::Drawing::Color> Factory::createColor()
{
	return std::make_shared<Color>();
}


std::shared_ptr<WorldConnector::Drawing::Font> Factory::createFont()
{
	return std::make_shared<Font>();
}


std::shared_ptr<WorldConnector::Drawing::Point> Factory::createPoint()
{
	return std::make_shared<Point>();
}


std::shared_ptr<WorldConnector::Drawing::PointF> Factory::createPointF()
{
	return std::make_shared<PointF>();
}


std::shared_ptr<WorldConnector::Drawing::Size> Factory::createSize()
{
	return std::make_shared<Size>();
}


std::shared_ptr<WorldConnector::Drawing::SizeF> Factory::createSizeF()
{
	return std::make_shared<SizeF>();
}

//###########################################################################

std::shared_ptr<WorldConnector::Form::Window> Factory::createWindow()
{
	auto win = std::make_shared<Window>();
	m_pWindow = win->getWindow();


	return win;
}


std::shared_ptr<WorldConnector::Form::Event> Factory::createEvent()
{
	return std::make_shared<Event>();
}


std::shared_ptr<WorldConnector::Form::Keyboard> Factory::createKeyboard()
{
	return std::make_shared<Keyboard>();
}


std::shared_ptr<WorldConnector::Form::Touch> Factory::createTouch()
{
	return std::make_shared<Touch>(m_pWindow);
}

