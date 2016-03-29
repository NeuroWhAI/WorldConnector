#ifndef __SFML_WC__TOUCH_H__
#define __SFML_WC__TOUCH_H__


#include <chrono>

#include "WorldConnector\Touch.h"




namespace sf
{
	class Window;
}


class Touch : public WorldConnector::Form::Touch
{
public:
	using Point = WorldConnector::Drawing::Point;
	using PointF = WorldConnector::Drawing::PointF;
	using system_clock = std::chrono::system_clock;


public:
	Touch(const sf::Window* window);
	virtual ~Touch();


protected:
	const sf::Window* m_win;


protected:
	bool m_oldState, m_currentState;

	system_clock::time_point m_touchDownTime;
	bool m_oldLongState, m_currentLongState;


public:
	virtual void update() override;


public:
	virtual bool isDown() const override;
	virtual bool isPressed() const override;
	virtual bool isUp() const override;

	virtual bool isLongDown() const override;
	virtual bool isLongPressed() const override;
	virtual bool isLongUp() const override;

	virtual std::shared_ptr<Point> getPosition() const override;
	virtual std::shared_ptr<PointF> getPositionF() const override;
	virtual void getPosition(int* pX, int* pY) const override;
	virtual void getPosition(float* pX, float* pY) const override;
};


#endif