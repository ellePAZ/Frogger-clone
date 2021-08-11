#pragma once

#include "SFML/Graphics.hpp"
#include "Vehicle.h"

class Truck : public Vehicle
{
private:
	float m_thisSpeed = 50;

public:
	Truck(sf::Vector2f p_startPos, int p_size);
	~Truck();

	virtual Vehicle* clone();
};