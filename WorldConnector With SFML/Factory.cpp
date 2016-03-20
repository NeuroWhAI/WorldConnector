#include "Factory.h"

#include "Size.h"




Factory::Factory()
{

}


Factory::~Factory()
{

}

//###########################################################################

std::shared_ptr<WorldConnector::Drawing::Size> Factory::createSize()
{
	return std::make_shared<Size>();
}


std::shared_ptr<WorldConnector::Drawing::SizeF> Factory::createSizeF()
{
	return std::make_shared<SizeF>();
}

