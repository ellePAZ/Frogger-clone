#include "Gui.h"

Gui::Gui(sf::Vector2f p_startPos, int p_startingLives, int p_frogSize) : m_frogSize(p_frogSize), m_livesStartPos(p_startPos)
{
	addLives(p_startingLives);
}

Gui::Gui()
{

}

Gui::~Gui()
{

}

void Gui::addLives(int p_addAmount)
{
	for (int i = 0; i < p_addAmount; i++)
	{
		Frog tempFrog{ m_livesStartPos + m_livesPadding * static_cast<float>(m_frogIcons.size()), m_frogSize, m_screenSize.x};

		m_frogIcons.push_back(tempFrog);
	}
}

void Gui::draw(sf::RenderWindow& window)
{
	for (auto& a : m_frogIcons)
	{
		window.draw(a);
	}
}

void Gui::removeLives()
{
	m_frogIcons.pop_back();
}
