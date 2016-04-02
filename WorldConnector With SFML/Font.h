#ifndef __SFML_WC__FONT_H__
#define __SFML_WC__FONT_H__


#include "WorldConnector\Font.h"

#include "SFML\Graphics.hpp"




class Font : public WorldConnector::Drawing::Font
{
public:
	using FontStyles = WorldConnector::Drawing::FontStyles;


public:
	Font();
	virtual ~Font();


protected:
	std::string m_name;
	int m_width, m_height;
	int m_styles;


public:
	virtual const char* getNamePtr() const override;
	virtual std::string getName() const override;
	virtual const wchar_t* getNameWPtr() const override;
	virtual std::wstring getNameW() const override;

	virtual void setName(const char name[]) override;
	virtual void setName(const std::string& name) override;
	virtual void setName(const wchar_t name[]) override;
	virtual void setName(const std::wstring& name) override;


public:
	virtual int getWidth() const override;
	virtual int getHeight() const override;

	virtual void setWidth(int width) override;
	virtual void setHeight(int height) override;


public:
	virtual int getStyle() const override;
	virtual bool checkStyle(int style) const override;
	virtual bool checkStyle(FontStyles style) const override;
	virtual bool isRegularStyle() const override;
	virtual bool hasBoldStyle() const override;
	virtual bool hasItalicStyle() const override;
	virtual bool hasStrikeOutStyle() const override;
	virtual bool hasUnderlineStyle() const override;

	virtual void setStyle(int style) override;
	virtual void setStyle(FontStyles style) override;

	virtual void addStyle(int style) override;
	virtual void addStyle(FontStyles style) override;

	virtual void removeStyle(int style) override;
	virtual void removeStyle(FontStyles style) override;
};


#endif