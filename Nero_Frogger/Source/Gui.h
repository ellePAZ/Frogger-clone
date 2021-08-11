#pragma once

#include "SFML/Graphics.hpp"
#include "Frog.h"

class Gui
{
	sf::Vector2i m_screenSize;

	std::vector<Frog> m_frogIcons;
	sf::Vector2f m_livesStartPos{ 30, 65 };
	sf::Vector2f m_livesPadding = sf::Vector2f(32,0);

	int m_frogSize = 0;

public:
	Gui();
	Gui(sf::Vector2f p_startPos, int p_startingLives, int p_frogSize);
	~Gui();

	void addLives(int p_addAmount);
	virtual void draw(sf::RenderWindow& window);

	void removeLives();
};