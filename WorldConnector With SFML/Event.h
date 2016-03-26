#ifndef __SFML_WC__EVENT_H__
#define __SFML_WC__EVENT_H__


#include "WorldConnector\Event.h"




class Event : public WorldConnector::Form::Event
{
public:
	Event();
	virtual ~Event();


protected:
	Types m_type;


public:
	virtual Types getType() const override;
	virtual void setType(Types type) override;
};


#endif