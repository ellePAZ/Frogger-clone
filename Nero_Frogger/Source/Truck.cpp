#include "Truck.h"

Truck::Truck(sf::Vector2f p_startPos, int p_size) : Vehicle(p_startPos, p_size)
{
	m_moveSpeed *= m_thisSpeed;

	// Vertex graphic design
	{
		m_shape = sf::VertexArray(sf::TrianglesStrip, 6);
		int padding = 3;
		m_shape[0].position = sf::Vector2f(p_startPos.x + m_size - padding, p_startPos.y + padding);
		m_shape[1].position = sf::Vector2f(p_startPos.x + m_size - padding, p_startPos.y + m_size - padding);
		m_shape[2].position = sf::Vector2f(p_startPos.x, p_startPos.y + padding);
		m_shape[3].position = sf::Vector2f(p_startPos.x, p_startPos.y + m_size - padding);
		m_shape[4].position = sf::Vector2f(p_startPos.x - (m_size * 2) - padding, p_startPos.y + padding);
		m_shape[5].position = sf::Vector2f(m_shape[4].position.x, m_shape[4].position.y + m_size - padding * 2);
		//m_shape[4].position = sf::Vector2f(midPoint.x - m_size * 0.3f, midPoint.y - m_size * 0.25f);

		m_shape[0].color = sf::Color::Green;
		m_shape[1].color = sf::Color::Green;
		m_shape[2].color = sf::Color::Green;
		m_shape[3].color = sf::Color::Yellow;
		m_shape[4].color = sf::Color::Yellow;
		m_shape[5].color = sf::Color::Yellow;
		//m_shape[5].color = sf::Color::Magenta;
	}

	sf::RectangleShape rectangle;

	sf::Vector2f wheelSize = sf::Vector2f(7, 7);

	for (int i = 2; i < 6; i++)
	{
		m_rectangles[i-2].setPosition(m_shape[i].position - sf::Vector2f(wheelSize.x / 2, wheelSize.y / 2));
		m_rectangles[i-2].setSize(wheelSize);
		m_rectangles[i-2].setFillColor(sf::Color::Blue);
	}
}

Truck::~Truck()
{

}

Vehicle* Truck::clone()
{
	return new Truck(getPosition(), m_size);
}