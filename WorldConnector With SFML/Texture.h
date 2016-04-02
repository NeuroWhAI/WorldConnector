#ifndef __SFML_WC__TEXTURE_H__
#define __SFML_WC__TEXTURE_H__


#include "WorldConnector\Texture.h"

#include "SFML\Graphics.hpp"




class Texture : public WorldConnector::Drawing::Texture
{
public:
	Texture();
	virtual ~Texture();


protected:
	sf::Texture m_tx;


public:
	virtual bool loadFromFile(const std::string& name) override;
	virtual bool loadFromFile(const std::wstring& name) override;
};


#endif