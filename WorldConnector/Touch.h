#ifndef __WC__TOUCH_H__
#define __WC__TOUCH_H__


#include <memory>

#include "WCUtility.h"




BEGIN_WC_DRAWING_NAMESPACE


template <typename T>
class PointT;
using Point = PointT<int>;
using PointF = PointT<float>;


END_WC_DRAWING_NAMESPACE


BEGIN_WC_FORM_NAMESPACE


class Touch
{
public:
	Touch();
	virtual ~Touch();


private:
	static std::shared_ptr<Touch> s_pInstance;

	class CleanUp
	{
	public:
		virtual ~CleanUp()
		{
			if (s_pInstance)
			{
				s_pInstance.reset();
			}
		}
	};

	static CleanUp s_cleaner;


public:
	static Touch* getInstance();


public:
	virtual void update() = 0;


public:
	virtual bool isDown() const = 0;
	virtual bool isPressed() const = 0;
	virtual bool isUp() const = 0;

	virtual bool isLongDown() const = 0;
	virtual bool isLongPressed() const = 0;
	virtual bool isLongUp() const = 0;

	virtual std::shared_ptr<Drawing::Point> getPosition() const = 0;
	virtual std::shared_ptr<Drawing::PointF> getPositionF() const = 0;
	virtual void getPosition(int* pX, int* pY) const = 0;
	virtual void getPosition(float* pX, float* pY) const = 0;
};


END_WC_FORM_NAMESPACE


#endif