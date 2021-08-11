#include "Entity.h"

Entity::Entity()
{
	
}

Entity::Entity(int p_size) : m_size(p_size)
{

}

Entity::~Entity()
{
	
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < sizeof(m_rectangles) / sizeof(m_rectangles[0]); i++)
	{
		if(&m_rectangles[i] != nullptr)
			target.draw(m_rectangles[i], this->getTransform());
	}

	target.draw(m_shape, this->getTransform());
}

sf::FloatRect Entity::getShapeBounds()
{
	return this->getTransform().transformRect(m_shape.getBounds());
}

int Entity::getSize()
{
	return m_size;
}