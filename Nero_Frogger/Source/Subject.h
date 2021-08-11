#pragma once

#include "Observer.h"
#include "Entity.h"
#include "Event.h"

class Subject
{
protected:
	Observer* m_observers[5]{ nullptr, nullptr, nullptr, nullptr, nullptr };
	int m_numObservers = 0;

public:
	~Subject();

	virtual void addObserver(Observer*);
	void removeObserver(Observer*);
	Observer* getObserver();

	void notify(Entity*, Event);
	void notify(Event);
};