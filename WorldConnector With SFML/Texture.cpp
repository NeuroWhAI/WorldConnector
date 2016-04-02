#include "Texture.h"




Texture::Texture()
{

}


Texture::~Texture()
{

}

//############################################################################

bool Texture::loadFromFile(const std::string& name)
{
	return m_tx.loadFromFile(name);
}


bool Texture::loadFromFile(const std::wstring& name)
{
	std::string temp;
	temp.assign(name.begin(), name.end());
	return m_tx.loadFromFile(temp);
}

