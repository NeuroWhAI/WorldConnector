#ifndef __WC__WINDOW_H__
#define __WC__WINDOW_H__


#include <memory>
#include <string>

#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


class Color;
template <typename T>
class SizeT;
using Size = SizeT<int>;
using SizeF = SizeT<float>;


END_WC_DRAWING_NAMESPACE


BEGIN_WC_FORM_NAMESPACE


class Event;


class Window
{
public:
	Window();
	virtual ~Window();


public:
	virtual void create(const Drawing::Size& size, const std::string title) = 0;
	virtual void create(const Drawing::Size& size, const std::wstring title) = 0;
	virtual void exit() = 0;

	virtual bool isRunning() const = 0;


public:
	virtual std::shared_ptr<Drawing::Size> getSize() const = 0;
	virtual void setSize(const Drawing::Size& newSize) = 0;
	virtual void setSize(int width, int height) = 0;

	virtual std::string getTitle() const = 0;
	virtual void setTitle(const std::string& newTitle) = 0;
	virtual std::wstring getTitleW() const = 0;
	virtual void setTitle(const std::wstring& newTitle) = 0;


public:
	virtual void show() = 0;
	virtual void hide() = 0;

	virtual bool isOpen() const = 0;


public:
	virtual bool pollEvent(Event* pop) = 0;


public:
	virtual void clearDrawing(const Drawing::Color& fillColor) = 0;
	virtual void displayDrawing() = 0;
	virtual void beginDraw() = 0;
	virtual void endDraw() = 0;
};


END_WC_FORM_NAMESPACE


#endif