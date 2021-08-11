#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Subject.h"
#include <iostream>

class Vehicle : public Entity, public Subject
{
protected:
	float m_moveSpeed = 1;
	float m_endPos = 0;

public:
	Vehicle(sf::Vector2f p_startPos, int p_size);
	virtual ~Vehicle();

	virtual void update(float);

	virtual Vehicle* clone() = 0;

};