#include "Factory.h"




BEGIN_WC_NAMESPACE


template <typename T>
void Factory::initializeInstance()
{
	if (s_pInstance != nullptr)
		delete s_pInstance;

	s_pInstance = new T();
}


END_WC_NAMESPACE

