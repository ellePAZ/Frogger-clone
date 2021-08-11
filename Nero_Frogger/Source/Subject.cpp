#include "Subject.h"

Subject::~Subject()
{
	for (auto& a : m_observers)
	{
		a = nullptr;
	}
}

void Subject::addObserver(Observer* p_observer)
{
	m_observers[m_numObservers] = p_observer;
	m_numObservers++;
}

void Subject::removeObserver(Observer* p_observer)
{
	for (auto& a : m_observers)
	{
		if (a == p_observer)
		{
			a = nullptr;
			break;
		}
	}
	m_numObservers--;
}

Observer* Subject::getObserver()
{
	return m_observers[0];
}

void Subject::notify(Entity* entity, Event event)
{
	for (int i = 0; i < m_numObservers; i++)
	{
		if (m_observers[i] != nullptr)
		{
			m_observers[i]->onNotify(entity, event);
		}
	}
}

void Subject::notify(Event p_event)
{
	for (int i = 0; i < m_numObservers; i++)
	{
		if (m_observers[i] != nullptr)
		{
			m_observers[i]->onNotify(p_event);
		}
	}
}
