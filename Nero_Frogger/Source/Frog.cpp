#include "Frog.h"


Frog::Frog(sf::Vector2f p_startPos, int p_size, int p_screenBounds) : Entity(p_size)
{
	this->setOrigin(p_startPos);
	this->setPosition(p_startPos + sf::Vector2f(m_size/2, m_size/2));

	m_screenBoundsHor = sf::Vector2i(0 + m_size / 2, p_screenBounds + m_size / 2);
	m_screenBoundsVer = sf::Vector2i(0, p_startPos.y);

	sf::Vector2f midPoint = sf::Vector2f(p_startPos.x + p_size / 2, p_startPos.y + p_size / 2);

	// Vertex graphic design
	{
		m_shape = sf::VertexArray(sf::TrianglesStrip, 6);

		m_shape[0].position = sf::Vector2f(midPoint.x - m_size * 0.25f, midPoint.y + m_size * 0.3f);
		m_shape[1].position = sf::Vector2f(midPoint.x + m_size * 0.25f, midPoint.y + m_size * 0.3f);
		m_shape[2].position = midPoint;
		m_shape[3].position = sf::Vector2f(midPoint.x - m_size * 0.25f, midPoint.y - m_size * 0.3f);
		m_shape[4].position = sf::Vector2f(midPoint.x + m_size * 0.25f, midPoint.y - m_size * 0.3f);
		m_shape[5].position = sf::Vector2f(midPoint.x, midPoint.y - m_size * 0.4f);

		m_shape[0].color = sf::Color::Green;
		m_shape[1].color = sf::Color::Green;
		m_shape[2].color = sf::Color::Green;
		m_shape[3].color = sf::Color::Green;
		m_shape[4].color = sf::Color::Green;
		m_shape[5].color = sf::Color::Green;
	}

	sf::RectangleShape rectangle;

	sf::Vector2f footSize = sf::Vector2f(7,7);

	m_rectangles[0].setPosition(m_shape[0].position - sf::Vector2f(footSize.x / 2, footSize.y / 2));
	m_rectangles[0].setSize(footSize);
	m_rectangles[0].setFillColor(sf::Color::Red);

	m_rectangles[1].setPosition(m_shape[1].position - sf::Vector2f(footSize.x / 2, footSize.y / 2));
	m_rectangles[1].setSize(footSize);
	m_rectangles[1].setFillColor(sf::Color::Red);

	m_rectangles[2].setPosition(m_shape[3].position - sf::Vector2f(footSize.x / 2, footSize.y / 2));
	m_rectangles[2].setSize(footSize);
	m_rectangles[2].setFillColor(sf::Color::Red);

	m_rectangles[3].setPosition(m_shape[4].position - sf::Vector2f(footSize.x / 2, footSize.y / 2));
	m_rectangles[3].setSize(footSize);
	m_rectangles[3].setFillColor(sf::Color::Red);

	setOrigin(m_shape[2].position);


	// Two different frog hop sounds wouldn't work, so i had to compromise
	if (!m_hopBuffer.loadFromFile("../Res/dp_finalfight.wav"))
	{

	}
	else
	{
		m_hopSound.setBuffer(m_hopBuffer);
	}	

	if (m_hopSound.getStatus() != sf::Sound::Status::Playing)
	{
		m_hopSound.play();
	}
}

Frog::~Frog()
{
	
}

void Frog::update(float p_deltaTime)
{
	if (!m_isMoving)
	{
		checkInput();
	}
	else
	{
		moveFrog();
	}

	this->move(m_verticalMove * p_deltaTime, 0);

	if (this->getPosition().x < m_screenBoundsHor.x)
	{
		this->setPosition(static_cast<float>(m_screenBoundsHor.x), this->getPosition().y);
	}
	else if (this->getPosition().x > static_cast<float>(m_screenBoundsHor.y))
	{
		this->setPosition(static_cast<float>(m_screenBoundsHor.y), this->getPosition().y);
	}
}

void Frog::checkInput()
{
	if (sf::Keyboard::isKeyPressed(m_upKey) && m_upPressed == false)
	{
		m_upPressed = true;
		m_jumpDist = sf::Vector2f(0, -m_size / moveTimes);
		m_isMoving = true;
		setRotation(0);
		playHopSound();
	}
	else if (!sf::Keyboard::isKeyPressed(m_upKey))
	{
		m_upPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(m_downKey) && m_downPressed == false)
	{
		m_downPressed = true;
		if (this->getPosition().y < m_screenBoundsVer.y)
		{
			m_jumpDist = sf::Vector2f(0, m_size / moveTimes);
			m_isMoving = true;
			setRotation(180);
			playHopSound();
		}	
	}
	else if (!sf::Keyboard::isKeyPressed(m_downKey))
	{
		m_downPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(m_leftKey) && m_leftPressed == false)
	{
		m_leftPressed = true;
		m_jumpDist = sf::Vector2f(-m_size / moveTimes, 0);
		m_isMoving = true;
		setRotation(270);
		playHopSound();
	}
	else if (!sf::Keyboard::isKeyPressed(m_leftKey))
	{
		m_leftPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(m_rightKey) && m_rightPressed == false)
	{
		m_rightPressed = true;
		m_jumpDist = sf::Vector2f(m_size / moveTimes, 0);
		m_isMoving = true;
		setRotation(90);
		playHopSound();
	}
	else if (!sf::Keyboard::isKeyPressed(m_rightKey))
	{
		m_rightPressed = false;
	}
}

void Frog::moveFrog()
{
	this->move(m_jumpDist);
	hasMoved++;

	if (hasMoved == moveTimes)
	{
		m_isMoving = false;
		hasMoved = 0;
	}
}

int Frog::getLives()
{
	return m_lives;
}

void Frog::takeDamage()
{
	m_lives--;
}

void Frog::setLives(int lives)
{
	m_lives = lives;
}

void Frog::setHorizontalMove(int p_vertMove)
{
	m_verticalMove = p_vertMove;
}

void Frog::setIsMoving(bool p_isMoving)
{
	m_isMoving = p_isMoving;
}

void Frog::reset()
{
	setIsMoving(false);
	setHorizontalMove(0);
	hasMoved = 0;
}

void Frog::playHopSound()
{
	if (m_hopSound.getStatus() != sf::Sound::Status::Playing)
	{
		m_hopSound.play();
	}
	else
	{
		m_hopSound.stop();
		m_hopSound.play();
	}
}
