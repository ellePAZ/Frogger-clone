#include "CarSlow.h"

CarSlow::CarSlow(const sf::Vector2f p_startPos, int p_size) : Vehicle(p_startPos, p_size)
{
	m_moveSpeed *= m_thisSpeed;

	sf::Vector2f midPoint = sf::Vector2f(p_startPos.x + p_size / 2, p_startPos.y + p_size / 2);;

	// Vertex graphic design
	{
		m_shape = sf::VertexArray(sf::TrianglesStrip, 5);

		m_shape[0].position = sf::Vector2f(midPoint.x - m_size * 0.3f, midPoint.y - m_size * 0.25f);
		m_shape[1].position = sf::Vector2f(midPoint.x - m_size * 0.3f, midPoint.y + m_size * 0.25f);
		m_shape[2].position = sf::Vector2f(midPoint.x + m_size * 0.3f, midPoint.y - m_size * 0.25f);
		m_shape[3].position = sf::Vector2f(midPoint.x + m_size * 0.3f, midPoint.y + m_size * 0.25f);
		//m_shape[4].position = sf::Vector2f(midPoint.x - m_size * 0.3f, midPoint.y - m_size * 0.25f);
		m_shape[4].position = sf::Vector2f(midPoint.x + m_size * 0.4f, midPoint.y);

		m_shape[0].color = sf::Color::Cyan;
		m_shape[1].color = sf::Color::Cyan;
		m_shape[2].color = sf::Color::Cyan;
		m_shape[3].color = sf::Color::Cyan;
		m_shape[4].color = sf::Color::Cyan;
		//m_shape[5].color = sf::Color::Magenta;
	}

	sf::RectangleShape rectangle;

	sf::Vector2f wheelSize = sf::Vector2f(7, 7);

	for (int i = 0; i < 4; i++)
	{
		m_rectangles[i].setPosition(m_shape[i].position - sf::Vector2f(wheelSize.x / 2, wheelSize.y / 2));
		m_rectangles[i].setSize(wheelSize);
		m_rectangles[i].setFillColor(sf::Color::Blue);
	}
}

CarSlow::~CarSlow()
{

}

Vehicle* CarSlow::clone()
{
	return new CarSlow(this->getPosition(), m_size);
}