#ifndef __SFML_WC__WINDOW_H__
#define __SFML_WC__WINDOW_H__


#include "WorldConnector\Window.h"

#include "SFML\Graphics.hpp"




class Window : public WorldConnector::Form::Window
{
public:
	using Color = WorldConnector::Drawing::Color;
	using Size = WorldConnector::Drawing::Size;
	using Event = WorldConnector::Form::Event;


public:
	Window();
	virtual ~Window();


protected:
	sf::RenderWindow m_window;


public:
	sf::RenderWindow* getWindow();


public:
	virtual void create(const Size& size, const std::string title) override;
	virtual void create(const Size& size, const std::wstring title) override;
	virtual void exit() override;

	virtual bool isRunning() const override;


public:
	virtual std::shared_ptr<Size> getSize() const override;
	virtual void setSize(const Size& newSize) override;
	virtual void setSize(int width, int height) override;

	virtual std::string getTitle() const override;
	virtual void setTitle(const std::string& newTitle) override;
	virtual std::wstring getTitleW() const override;
	virtual void setTitle(const std::wstring& newTitle) override;


public:
	virtual void show() override;
	virtual void hide() override;

	virtual bool isOpen() const override;


public:
	virtual bool pollEvent(Event* pop) override;


public:
	virtual void clearDrawing(const Color& fillColor) override;
	virtual void displayDrawing() override;
	virtual void beginDraw() override;
	virtual void endDraw() override;
};


#endif