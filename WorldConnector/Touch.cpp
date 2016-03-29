#include "Touch.h"

#include "Factory.h"




BEGIN_WC_FORM_NAMESPACE


Touch::Touch()
{

}


Touch::~Touch()
{

}

//##########################################################################

std::shared_ptr<Touch> Touch::s_pInstance = nullptr;
Touch::CleanUp Touch::s_cleaner;

//##########################################################################

Touch* Touch::getInstance()
{
	if (!s_pInstance)
	{
		s_pInstance = Factory::getInstance()->createTouch();
	}

	return s_pInstance.get();
}


END_WC_FORM_NAMESPACE

