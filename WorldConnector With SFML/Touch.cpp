#include "Touch.h"

#include "SFML\Window.hpp"

#include "Point.h"




Touch::Touch(const sf::Window* window)
	: m_win(window)
	
	, m_oldState(false)
	, m_currentState(false)
	, m_oldLongState(false)
	, m_currentLongState(false)
{

}


Touch::~Touch()
{

}

//############################################################################

void Touch::update()
{
	m_oldState = m_currentState;
	m_currentState = sf::Touch::isDown(0)
		|| sf::Mouse::isButtonPressed(sf::Mouse::Left);


	m_oldLongState = m_currentLongState;

	if (isDown())
	{
		m_touchDownTime = system_clock::now();
	}
	else if (isUp())
	{
		m_currentLongState = false;
	}
	else if(isPressed() && !m_currentLongState)
	{
		std::chrono::duration<double> timespan =
			system_clock::now() - m_touchDownTime;

		if (timespan.count() > 1.0)
		{
			m_currentLongState = true;
		}
	}
}

//############################################################################

bool Touch::isDown() const
{
	return (!m_oldState && m_currentState);
}


bool Touch::isPressed() const
{
	return (m_oldState && m_currentState);
}


bool Touch::isUp() const
{
	return (m_oldState && !m_currentState);
}

//--------------------------------------------------------------------------

bool Touch::isLongDown() const
{
	return (!m_oldLongState && m_currentLongState);
}


bool Touch::isLongPressed() const
{
	return (m_oldLongState && m_currentLongState);
}


bool Touch::isLongUp() const
{
	return (m_oldLongState && !m_currentLongState);
}

//--------------------------------------------------------------------------

std::shared_ptr<WorldConnector::Drawing::Point> Touch::getPosition() const
{
	int x = 0, y = 0;
	getPosition(&x, &y);


	auto cursor = std::make_shared<::Point>();
	cursor->setLocation(x, y);


	return cursor;
}


std::shared_ptr<WorldConnector::Drawing::PointF> Touch::getPositionF() const
{
	float x = 0, y = 0;
	getPosition(&x, &y);


	auto cursor = std::make_shared<::PointF>();
	cursor->setLocation(x, y);


	return cursor;
}


void Touch::getPosition(int* pX, int* pY) const
{
	auto cursor = sf::Mouse::getPosition(*m_win);
	*pX = cursor.x;
	*pY = cursor.y;
}


void Touch::getPosition(float* pX, float* pY) const
{
	auto cursor = sf::Mouse::getPosition(*m_win);
	*pX = static_cast<float>(cursor.x);
	*pY = static_cast<float>(cursor.y);
}

