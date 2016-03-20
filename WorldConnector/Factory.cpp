#include "Factory.h"




BEGIN_WC_NAMESPACE


Factory::Factory()
{

}


Factory::~Factory()
{

}

//###########################################################################

Factory* Factory::s_pInstance = nullptr;
Factory::CleanUp Factory::s_cleaner;

//###########################################################################

Factory* Factory::getInstance()
{
	return s_pInstance;
}


END_WC_NAMESPACE

