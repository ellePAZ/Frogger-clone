#include "CarFast.h"

CarFast::CarFast(sf::Vector2f p_startPos, int p_size) : Vehicle(p_startPos, p_size)
{
	m_moveSpeed *= m_thisSpeed;

	sf::Vector2f midPoint = sf::Vector2f(p_startPos.x + p_size / 2, p_startPos.y + p_size / 2);;

	// Vertex graphic design
	{
		m_shape = sf::VertexArray(sf::TrianglesStrip, 5);

		m_shape[0].position = sf::Vector2f(midPoint.x - m_size * 0.5f, midPoint.y - m_size * 0.15f);
		m_shape[1].position = sf::Vector2f(midPoint.x - m_size * 0.5f, midPoint.y + m_size * 0.15f);
		m_shape[2].position = sf::Vector2f(midPoint.x + m_size * 0.5f, midPoint.y - m_size * 0.15f);
		m_shape[3].position = sf::Vector2f(midPoint.x + m_size * 0.5f, midPoint.y + m_size * 0.15f);
		//m_shape[4].position = sf::Vector2f(midPoint.x - m_size * 0.3f, midPoint.y - m_size * 0.25f);
		m_shape[4].position = sf::Vector2f(midPoint.x + m_size * 0.8f, midPoint.y);

		for (int i = 0; i < sizeof(m_shape) / sizeof(m_shape[0]); i++)
		{
			m_shape[i].color = sf::Color::White;
		}

		m_wing = sf::VertexArray(sf::Triangles, 3);

		m_wing[0].position = m_shape[0].position + sf::Vector2f(m_size * -0.2f, m_size * -0.2f);
		m_wing[1].position = m_shape[1].position + sf::Vector2f(m_size * -0.2f, m_size * 0.2f);
		m_wing[2].position = midPoint;

		for (int i = 0; i < sizeof(m_wing) / sizeof(m_wing[0]); i++)
		{
			m_shape[i].color = sf::Color::White;
		}
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

CarFast::~CarFast()
{
	
}

void CarFast::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < sizeof(m_rectangles) / sizeof(m_rectangles[0]); i++)
	{
		target.draw(m_rectangles[i], this->getTransform());
	}

	target.draw(m_shape, this->getTransform());
	target.draw(m_wing, this->getTransform());
}

Vehicle* CarFast::clone()
{
	return new CarFast(getPosition(), m_size);
}