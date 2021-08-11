#include "Vehicle.h"

Vehicle::Vehicle(sf::Vector2f p_startPos, int p_size) : Entity(p_size)
{
	this->setOrigin(p_startPos);
	this->setPosition(p_startPos);

	if (p_startPos.x > 0)
	{
		m_moveSpeed *= -1;
		this->setScale(-1, 1);
	}
}

Vehicle::~Vehicle()
{
	
}

void Vehicle::update(float p_deltaTime)
{
	this->move(sf::Vector2f(m_moveSpeed * p_deltaTime, 0));
}
