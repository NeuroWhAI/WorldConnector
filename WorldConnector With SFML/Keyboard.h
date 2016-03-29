#ifndef __SFML_WC__KEYBOARD_H__
#define __SFML_WC__KEYBOARD_H__


#include "WorldConnector\Keyboard.h"

#include "SFML\Window.hpp"




class Keyboard : public WorldConnector::Form::Keyboard
{
public:
	using Keys = WorldConnector::Form::Keys;


public:
	Keyboard();
	virtual ~Keyboard();


protected:
	bool m_oldKeyMap[sf::Keyboard::KeyCount];
	bool m_currentKeyMap[sf::Keyboard::KeyCount];


protected:
	sf::Keyboard::Key convertToSFML(Keys key) const;


public:
	virtual void update() override;


public:
	virtual bool isKeyDown(Keys key) const override;
	virtual bool isKeyPressed(Keys key) const override;
	virtual bool isKeyUp(Keys key) const override;
};


#endif