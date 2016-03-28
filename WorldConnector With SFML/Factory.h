#ifndef __SFML_WC__FACTORY_H__
#define __SFML_WC__FACTORY_H__


#include "WorldConnector\Factory.h"




namespace sf
{
	class RenderWindow;
}


class Factory : public WorldConnector::Factory
{
public:
	Factory();
	virtual ~Factory();


protected:
	sf::RenderWindow* m_pWindow;


public:
	virtual std::shared_ptr<WorldConnector::Drawing::Graphics> createGraphics() override;
	virtual std::shared_ptr<WorldConnector::Drawing::Color> createColor() override;
	virtual std::shared_ptr<WorldConnector::Drawing::Font> createFont() override;
	virtual std::shared_ptr<WorldConnector::Drawing::Point> createPoint() override;
	virtual std::shared_ptr<WorldConnector::Drawing::PointF> createPointF() override;
	virtual std::shared_ptr<WorldConnector::Drawing::Size> createSize() override;
	virtual std::shared_ptr<WorldConnector::Drawing::SizeF> createSizeF() override;


public:
	virtual std::shared_ptr<WorldConnector::Form::Window> createWindow() override;
	virtual std::shared_ptr<WorldConnector::Form::Event> createEvent() override;
	virtual std::shared_ptr<WorldConnector::Form::Keyboard> createKeyboard() override;
};


#endif