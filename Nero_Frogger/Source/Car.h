#pragma once

#include "SFML/Graphics.hpp"
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	float m_thisSpeed = 50;

public:
	Car(const sf::Vector2f p_startPos, int p_size);
	~Car();

	virtual Vehicle* clone();
};