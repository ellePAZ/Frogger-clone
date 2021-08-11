#include "CarHotDog.h"

CarHotDog::CarHotDog(sf::Vector2f p_startPos, int p_size) : Vehicle(p_startPos, p_size)
{
	m_moveSpeed *= m_thisSpeed;

	sf::Vector2f midPoint = sf::Vector2f(p_startPos.x + p_size / 2, p_startPos.y + p_size / 2);;

	// Vertex graphic design
	{
		m_shape = sf::VertexArray(sf::TriangleStrip, 5);

		m_shape[0].position = sf::Vector2f(midPoint.x - m_size * 0.8f, midPoint.y - m_size * 0.35f);
		m_shape[1].position = sf::Vector2f(midPoint.x - m_size * 0.8f, midPoint.y + m_size * 0.35f);
		m_shape[2].position = sf::Vector2f(midPoint.x + m_size * 0.8f, midPoint.y - m_size * 0.35f);
		m_shape[3].position = sf::Vector2f(midPoint.x + m_size * 0.8f, midPoint.y + m_size * 0.35f);
		m_shape[4].position = sf::Vector2f(midPoint.x + m_size * 0.8f, midPoint.y);

		m_shape[0].color = sf::Color::Yellow;
		m_shape[1].color = sf::Color::Yellow;
		m_shape[2].color = sf::Color::Yellow;
		m_shape[3].color = sf::Color::Yellow;
		m_shape[4].color = sf::Color::Yellow;

		for (int i = 0; i < sizeof(m_shape) / sizeof(m_shape[0]); i++)
		{
			m_shape[i].color = sf::Color::Yellow;
		}
	}

	m_body.setSize(sf::Vector2f(50, 10));
	m_body.setOrigin(sf::Vector2f(m_body.getSize().x / 2, m_body.getSize().y / 2));
	m_body.setPosition(midPoint);
	m_body.setFillColor(sf::Color(185, 39, 23));

	sf::RectangleShape rectangle;

	sf::Vector2f wheelSize = sf::Vector2f(7, 7);

	for (int i = 0; i < 4; i++)
	{
		m_rectangles[i].setPosition(m_shape[i].position - sf::Vector2f(wheelSize.x / 2, wheelSize.y / 2));
		m_rectangles[i].setSize(wheelSize);
		m_rectangles[i].setFillColor(sf::Color::Blue);
	}
}

CarHotDog::~CarHotDog()
{

}

void CarHotDog::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < sizeof(m_rectangles) / sizeof(m_rectangles[0]); i++)
	{
		target.draw(m_rectangles[i], this->getTransform());
	}

	target.draw(m_shape, this->getTransform());
	target.draw(m_body, getTransform());
}

Vehicle* CarHotDog::clone()
{
	return new CarHotDog(getPosition(), m_size);
}