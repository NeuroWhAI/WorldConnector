#ifndef __WC__FONT_H__
#define __WC__FONT_H__


#include <string>

#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


enum FontStyles : int
{
	Regular = 0,
	Bold = 1,
	Italic = 1 << 1,
	StrikeOut = 1 << 2,
	Underline = 1 << 3,
};


class Font
{
public:
	Font();
	virtual ~Font();


public:
	virtual const char* getNamePtr() const = 0;
	virtual std::string getName() const = 0;
	virtual const wchar_t* getNameWPtr() const = 0;
	virtual std::wstring getNameW() const = 0;

	virtual void setName(const char name[]) = 0;
	virtual void setName(const std::string name) = 0;
	virtual void setName(const wchar_t name[]) = 0;
	virtual void setName(const std::wstring name) = 0;


public:
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	virtual void setWidth(int width) = 0;
	virtual void setHeight(int height) = 0;


public:
	virtual int getStyle() const = 0;
	virtual bool checkStyle(int style) const = 0;
	virtual bool checkStyle(FontStyles style) const = 0;
	virtual bool isRegularStyle() const = 0;
	virtual bool hasBoldStyle() const = 0;
	virtual bool hasItalicStyle() const = 0;
	virtual bool hasStrikeOutStyle() const = 0;
	virtual bool hasUnderlineStyle() const = 0;

	virtual void setStyle(int style) = 0;
	virtual void setStyle(FontStyles style) = 0;

	virtual void addStyle(int style) = 0;
	virtual void addStyle(FontStyles style) = 0;

	virtual void removeStyle(int style) = 0;
	virtual void removeStyle(FontStyles style) = 0;
};


END_WC_DRAWING_NAMESPACE


#endif