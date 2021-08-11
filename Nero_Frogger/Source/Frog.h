#pragma once

#include "Entity.h"
#include "SFML/Audio.hpp"

class Frog : public Entity
{
private:
	sf::Vector2f m_jumpDist;
	
	sf::Keyboard::Key m_upKey = sf::Keyboard::Key::Up;
	sf::Keyboard::Key m_leftKey = sf::Keyboard::Key::Left;
	sf::Keyboard::Key m_rightKey = sf::Keyboard::Key::Right;
	sf::Keyboard::Key m_downKey = sf::Keyboard::Key::Down;

	bool m_upPressed = false;
	bool m_downPressed = false;
	bool m_leftPressed = false;
	bool m_rightPressed = false;

	bool m_isMoving = false;

	int moveTimes = 4;
	int hasMoved = 0;

	int m_lives = 3;
	int m_verticalMove = 0;

	sf::Vector2i m_screenBoundsVer;
	sf::Vector2i m_screenBoundsHor;

	sf::Vector2f m_origin;

	sf::SoundBuffer m_hopBuffer;
	sf::Sound m_hopSound;

public:
	Frog(sf::Vector2f p_startPos, int p_size, int p_screenBounds);
	~Frog();

	void update(float p_deltaTime);
	void checkInput();
	void moveFrog();

	int getLives();
	void takeDamage();
	void setLives(int lives);

	void setHorizontalMove(int);
	void setIsMoving(bool p_isMoving);
	void reset();

	void playHopSound();
};