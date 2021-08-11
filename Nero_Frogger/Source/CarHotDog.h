#pragma once

#include "SFML/Graphics.hpp"
#include "Vehicle.h"

class CarHotDog : public Vehicle
{
private:
	float m_speedFactor = 1;
	float m_thisSpeed = 75;

	sf::RectangleShape m_body;

public:
	CarHotDog(sf::Vector2f p_startPos, int p_size);
	~CarHotDog();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual Vehicle* clone();
};