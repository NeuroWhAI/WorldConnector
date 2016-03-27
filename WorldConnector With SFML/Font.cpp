#include "Font.h"




Font::Font()
{

}


Font::~Font()
{

}

//###########################################################################

const char* Font::getNamePtr() const
{
	return m_name.c_str();
}


std::string Font::getName() const
{
	return m_name;
}


const wchar_t* Font::getNameWPtr() const
{
	throw std::exception("지원하지 않는 기능입니다.");
}


std::wstring Font::getNameW() const
{
	throw std::exception("지원하지 않는 기능입니다.");
}

//--------------------------------------------------------------------------

void Font::setName(const char name[])
{
	m_name = name;
}


void Font::setName(const std::string name)
{
	m_name = name;
}


void Font::setName(const wchar_t name[])
{
	throw std::exception("지원하지 않는 기능입니다.");
}


void Font::setName(const std::wstring name)
{
	throw std::exception("지원하지 않는 기능입니다.");
}

//###########################################################################

int Font::getWidth() const
{
	return m_width;
}


int Font::getHeight() const
{
	return m_height;
}

//--------------------------------------------------------------------------

void Font::setWidth(int width)
{
	m_width = width;
}


void Font::setHeight(int height)
{
	m_height = height;
}

//###########################################################################

int Font::getStyle() const
{
	return m_styles;
}


bool Font::checkStyle(int style) const
{
	int gap = m_styles - style;
	int match = m_styles & (~style);

	return (gap == match);
}


bool Font::checkStyle(FontStyles style) const
{
	return ((m_styles & style) != 0);
}


bool Font::isRegularStyle() const
{
	return (m_styles == FontStyles::Regular);
}


bool Font::hasBoldStyle() const
{
	return (checkStyle(FontStyles::Bold));
}


bool Font::hasItalicStyle() const
{
	return (checkStyle(FontStyles::Italic));
}


bool Font::hasStrikeOutStyle() const
{
	return (checkStyle(FontStyles::StrikeOut));
}


bool Font::hasUnderlineStyle() const
{
	return (checkStyle(FontStyles::Underline));
}

//--------------------------------------------------------------------------

void Font::setStyle(int style)
{
	m_styles = style;
}


void Font::setStyle(FontStyles style)
{
	m_styles = style;
}

//--------------------------------------------------------------------------

void Font::addStyle(int style)
{
	m_styles |= style;
}


void Font::addStyle(FontStyles style)
{
	m_styles |= style;
}

//--------------------------------------------------------------------------

void Font::removeStyle(int style)
{
	m_styles &= (~style);
}


void Font::removeStyle(FontStyles style)
{
	m_styles &= (~style);
}

