#ifndef __SFML_WC__FACTORY_H__
#define __SFML_WC__FACTORY_H__


#include "WorldConnector\Factory.h"




class Factory : public WorldConnector::Factory
{
public:
	Factory();
	virtual ~Factory();


public:
	virtual std::shared_ptr<WorldConnector::Drawing::Size> createSize() override;
	virtual std::shared_ptr<WorldConnector::Drawing::SizeF> createSizeF() override;
};


#endif