#ifndef __WC__TEXTURE_H__
#define __WC__TEXTURE_H__


#include <string>

#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


class Texture
{
public:
	Texture();
	virtual ~Texture();


public:
	virtual bool loadFromFile(const std::string& name) = 0;
	virtual bool loadFromFile(const std::wstring& name) = 0;
};


END_WC_DRAWING_NAMESPACE


#endif