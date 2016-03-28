#include "Event.h"




using Types = Event::Types;




Event::Event()
	: m_type(Types::Unknown)
{

}


Event::~Event()
{

}

//###########################################################################

Types Event::getType() const
{
	return m_type;
}


void Event::setType(Types type)
{
	m_type = type;
}

