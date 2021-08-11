#pragma once

#include "SFML/Graphics.hpp"
#include "Vehicle.h"

class CarFast : public Vehicle
{
private:
	float m_speedFactor = 1;
	float m_thisSpeed = 75;

	sf::VertexArray m_wing;

public:
	CarFast(sf::Vector2f p_startPos, int p_size);
	~CarFast();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	virtual Vehicle* clone();
};