#include "Log.h"

Log::Log(int p_size, int p_length, sf::Vector2f p_startPos, float p_moveSpeed) : m_length(p_length), Entity(p_size)
{
	m_moveSpeed = p_moveSpeed;
	m_originalSpeed = m_moveSpeed;

	if (m_moveSpeed < 0)
	{
		m_endPoint = 0 - static_cast<float>(p_size) * (4 + 1);
		m_spawnPoint = 640;
		m_goingLeft = true;
	}
	else
	{
		m_endPoint = 640;
		m_spawnPoint = 0 - static_cast<float>(p_size) * (4 + 1);
	}
	
	this->setPosition(p_startPos);
	this->setOrigin(p_startPos);

	sf::RectangleShape rectangle;

	sf::Color color(255, 100, 100);

	m_rectangles[0].setPosition(p_startPos);
	m_rectangles[0].setSize(sf::Vector2f(p_size * p_length, p_size));
	m_rectangles[0].setFillColor(color);
}

void Log::update(float p_deltaTime)
{
	this->move(m_moveSpeed * p_deltaTime, 0);
	
	if (m_goingLeft)
	{
		if (this->getPosition().x < m_endPoint)
		{
			this->setPosition(m_spawnPoint, this->getPosition().y);
		}
	}
	else
	{
		if (this->getPosition().x > m_endPoint)
		{
			this->setPosition(m_spawnPoint, this->getPosition().y);
		}
	}
}

sf::FloatRect Log::getShapeBounds()
{
	return this->getTransform().transformRect(m_rectangles[0].getGlobalBounds());
}

float Log::getMoveSpeed()
{
	return m_moveSpeed;
}

void Log::resetSpeed()
{
	m_moveSpeed = m_originalSpeed;
}

void Log::increaseMoveSpeed(float p_moveSpeed)
{
	m_moveSpeed *= p_moveSpeed;
}
