#include "Factory.h"

#include "Graphics.h"
#include "Color.h"
#include "Size.h"




Factory::Factory()
{

}


Factory::~Factory()
{

}

//###########################################################################

std::shared_ptr<WorldConnector::Drawing::Graphics> Factory::createGraphics()
{
	return std::make_shared<Graphics>();
}


std::shared_ptr<WorldConnector::Drawing::Color> Factory::createColor()
{
	return std::make_shared<Color>();
}


std::shared_ptr<WorldConnector::Drawing::Size> Factory::createSize()
{
	return std::make_shared<Size>();
}


std::shared_ptr<WorldConnector::Drawing::SizeF> Factory::createSizeF()
{
	return std::make_shared<SizeF>();
}

