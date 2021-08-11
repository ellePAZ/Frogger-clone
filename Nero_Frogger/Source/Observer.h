#pragma once
#include "Entity.h"
#include "Event.h"
#include <iostream>

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void onNotify(Entity* entity, Event event) = 0;
	virtual void onNotify(Event event) = 0;

};