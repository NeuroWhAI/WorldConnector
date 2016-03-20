#ifndef __WC__FACTORY_H__
#define __WC__FACTORY_H__


#include <memory>

#include "WCUtility.h"
#include "WCMain.h"




BEGIN_WC_NAMESPACE


class Factory
{
public:
	Factory();
	virtual ~Factory();


private:
	static Factory* s_pInstance;

	class CleanUp
	{
	public:
		virtual ~CleanUp()
		{
			if (s_pInstance != nullptr)
			{
				delete s_pInstance;
				s_pInstance = nullptr;
			}
		}
	};

	static CleanUp s_cleaner;


public:
	template <typename T>
	static void initializeInstance();
	static Factory* getInstance();


public:
	virtual std::shared_ptr<Drawing::Size> createSize() = 0;
	virtual std::shared_ptr<Drawing::SizeF> createSizeF() = 0;
};


END_WC_NAMESPACE


#include "Factory.inl"


#endif