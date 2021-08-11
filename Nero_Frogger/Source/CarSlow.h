#pragma once
#include "SFML/Graphics.hpp"
#include "Vehicle.h"

class CarSlow : public Vehicle
{
private:
	float m_thisSpeed = 35;

public:
	CarSlow(const sf::Vector2f p_startPos, int p_size);
	~CarSlow();

	virtual Vehicle* clone();
};
