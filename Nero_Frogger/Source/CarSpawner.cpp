#include "CarSpawner.h"

CarSpawner::CarSpawner(Vehicle* p_prototype, sf::Vector2f p_startPos) : m_prototype(p_prototype)
{
	this->setOrigin(p_startPos);
	this->setPosition(p_startPos);

	m_prototype->setPosition(this->getPosition());

	srand(time(0));

	m_clock.restart();
}

CarSpawner::~CarSpawner()
{

}

void CarSpawner::update(float p_deltaTime)
{
	if (m_clock.getElapsedTime().asSeconds() > m_interval && m_isSpawning)
	{
		if (m_observers[0] != nullptr)
		{
			notify(m_prototype->clone(), Event::VEHICLE_SPAWN_EVENT);
		}
		m_clock.restart();

		float random = ((float)rand()) / (float)RAND_MAX;
		float diff = m_maxTime - m_minTime;
		float r = random * diff;
		m_interval = m_minTime + r;
	}
}

void CarSpawner::setPrototype(Vehicle* p_prototype)
{
	m_prototype = p_prototype;
	m_prototype->setPosition(this->getPosition());
}

void CarSpawner::decreaseMinMax(float p_divisor)
{
	m_minTime /= p_divisor;
}

void CarSpawner::doubleMin()
{
	m_minTime *= 2;
}

void CarSpawner::resetSpawnRate()
{
	m_minTime = m_origMinTime;
	m_maxTime = m_origMaxTime;
}

void CarSpawner::setSpawning(bool p_isSpawning)
{
	m_isSpawning = p_isSpawning;
}
