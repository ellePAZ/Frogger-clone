#pragma once

#include "SFML/Graphics.hpp"

class Entity : public sf::Drawable, public sf::Transformable
{
protected:
	sf::VertexArray m_shape;
	sf::RectangleShape m_rectangles[4];

	int m_size = 5;
	

public:
	Entity();
	Entity(int p_size);
	virtual ~Entity();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update(float p_deltaTime) = 0;
	virtual sf::FloatRect getShapeBounds();

	int getSize();

	bool m_isDrawing = false;
};