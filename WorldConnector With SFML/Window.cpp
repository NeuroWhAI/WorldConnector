#include "Window.h"

#include "SFML\Graphics.hpp"

#include "Color.h"
#include "Size.h"
#include "Event.h"




//###########################################################################

Window::Window()
{

}


Window::~Window()
{

}

//###########################################################################

sf::RenderWindow* Window::getWindow()
{
	return &m_window;
}

//###########################################################################

void Window::create(const Size& size, const std::string title)
{
	m_window.create(sf::VideoMode(size.getWidth(), size.getHeight()),
		title.c_str());
}


void Window::create(const Size& size, const std::wstring title)
{
	m_window.create(sf::VideoMode(size.getWidth(), size.getHeight()),
		title.c_str());
}


void Window::exit()
{
	m_window.close();
}

//--------------------------------------------------------------------------

bool Window::isRunning() const
{
	return m_window.isOpen();
}

//###########################################################################

std::shared_ptr<Window::Size> Window::getSize() const
{
	auto size = m_window.getSize();

	auto result = std::make_shared<::Size>();
	result->setWidth(size.x);
	result->setHeight(size.y);


	return result;
}


void Window::setSize(const Size& newSize)
{
	m_window.setSize(sf::Vector2u(newSize.getWidth(), newSize.getHeight()));
}


void Window::setSize(int width, int height)
{
	m_window.setSize(sf::Vector2u(width, height));
}

//--------------------------------------------------------------------------

std::string Window::getTitle() const
{
	throw std::exception("지원하지 않는 기능입니다.");
}


void Window::setTitle(const std::string& newTitle)
{
	m_window.setTitle(newTitle.c_str());
}


std::wstring Window::getTitleW() const
{
	throw std::exception("지원하지 않는 기능입니다.");
}


void Window::setTitle(const std::wstring& newTitle)
{
	m_window.setTitle(newTitle.c_str());
}

//###########################################################################

void Window::show()
{
	m_window.setActive(true);
}


void Window::hide()
{
	m_window.setActive(false);
}

//--------------------------------------------------------------------------

bool Window::isOpen() const
{
	return m_window.hasFocus();
}

//###########################################################################

bool Window::pollEvent(Event* pop)
{
	sf::Event newEvent;
	if (m_window.pollEvent(newEvent))
	{
		switch (newEvent.type)
		{
		case sf::Event::Closed:
			pop->setType(Event::Types::Closed);
			break;

		case sf::Event::Resized:
			pop->setType(Event::Types::Resized);
			pop->size.width = newEvent.size.width;
			pop->size.height = newEvent.size.height;
			break;

		case sf::Event::KeyPressed:
			pop->setType(Event::Types::KeyDown);
			pop->key.code = newEvent.key.code;
			break;

		case sf::Event::KeyReleased:
			pop->setType(Event::Types::KeyUp);
			pop->key.code = newEvent.key.code;
			break;

		case sf::Event::MouseButtonPressed:
			pop->setType(Event::Types::TouchBegan);
			pop->touch.x = newEvent.mouseButton.x;
			pop->touch.y = newEvent.mouseButton.y;
			break;

		case sf::Event::MouseButtonReleased:
			pop->setType(Event::Types::TouchEnded);
			pop->touch.x = newEvent.mouseButton.x;
			pop->touch.y = newEvent.mouseButton.y;
			break;

		case sf::Event::TouchBegan:
			pop->setType(Event::Types::TouchBegan);
			pop->touch.x = newEvent.touch.x;
			pop->touch.y = newEvent.touch.y;
			break;

		case sf::Event::TouchMoved:
			pop->setType(Event::Types::TouchMoved);
			pop->touch.x = newEvent.touch.x;
			pop->touch.y = newEvent.touch.y;
			break;

		case sf::Event::TouchEnded:
			pop->setType(Event::Types::TouchEnded);
			pop->touch.x = newEvent.touch.x;
			pop->touch.y = newEvent.touch.y;
			break;

		case sf::Event::MouseWheelScrolled:
			pop->setType(Event::Types::Scrolled);
			pop->scroll.delta = newEvent.mouseWheelScroll.delta;
			break;
		}


		return true;
	}


	pop->setType(Event::Types::Null);
	return false;
}

//###########################################################################

void Window::clearDrawing(const Color& fillColor)
{
	m_window.clear(sf::Color(
		fillColor.getR(),
		fillColor.getG(),
		fillColor.getB(),
		fillColor.getA()));
}


void Window::displayDrawing()
{
	m_window.display();
}


void Window::beginDraw()
{
	// empty
}


void Window::endDraw()
{
	// empty
}

