#pragma once

#include "SFML/Graphics.hpp"
#include "Subject.h"
#include "Observer.h"

class StartMenu : public Subject
{
	sf::RectangleShape m_backGround;
	sf::Font m_font;
	sf::Text m_titleText;
	sf::Text m_startText;

	sf::Keyboard::Key m_space = sf::Keyboard::Key::Space;
	bool m_spacePressed = false;

public:
	StartMenu(sf::Vector2f p_screenSize, Observer* p_observer);
	~StartMenu();

	void update(float p_deltaTime);

	void draw(sf::RenderTarget& target);

	int getAmountOfObservers();

	void addObserver(Observer* p_observer);

};