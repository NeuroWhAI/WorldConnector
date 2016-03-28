#include "Keyboard.h"

#include "Factory.h"




BEGIN_WC_FORM_NAMESPACE


Keyboard::Keyboard()
{

}


Keyboard::~Keyboard()
{

}

//##########################################################################

std::shared_ptr<Keyboard> Keyboard::s_pInstance = nullptr;
Keyboard::CleanUp Keyboard::s_cleaner;

//##########################################################################

Keyboard* Keyboard::getInstance()
{
	if (!s_pInstance)
	{
		s_pInstance = Factory::getInstance()->createKeyboard();
	}

	return s_pInstance.get();
}


END_WC_FORM_NAMESPACE

