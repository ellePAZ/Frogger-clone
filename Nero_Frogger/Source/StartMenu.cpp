#include "StartMenu.h"

StartMenu::StartMenu(sf::Vector2f p_screenSize, Observer* p_observer)
{
	addObserver(p_observer);

	m_backGround = sf::RectangleShape(p_screenSize);
	m_backGround.setFillColor(sf::Color::Black);

	if (!m_font.loadFromFile("../Res/Fresh Lychee.ttf"))
	{

	}

	m_titleText.setOrigin(0, 0);
	m_titleText.setFont(m_font);
	m_titleText.setString("Frogster");
	m_titleText.setPosition(p_screenSize.x / 2 - m_titleText.getLocalBounds().width, 5);
	m_titleText.setCharacterSize(50);
	m_titleText.setFillColor(sf::Color::Red);

	m_startText.setOrigin(0, 0);
	m_startText.setFont(m_font);
	m_startText.setString("Press SPACE to start game");
	m_startText.setPosition(p_screenSize.x / 2 - m_titleText.getLocalBounds().width, p_screenSize.y / 2);
	m_startText.setCharacterSize(25);
	m_startText.setFillColor(sf::Color::White);
}

StartMenu::~StartMenu()
{
	m_observers[0] = nullptr;
}

void StartMenu::update(float p_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(m_space) && m_spacePressed == false)
	{
		m_spacePressed = true;
		if(m_observers[0] != nullptr)
			notify(Event::PLAYER_SPAWN_EVENT);
	}
}

void StartMenu::draw(sf::RenderTarget& target)
{
	target.draw(m_backGround);
	target.draw(m_titleText);
	target.draw(m_startText);
}

int StartMenu::getAmountOfObservers()
{
	return sizeof(m_observers) / sizeof(m_observers[0]);
}

void StartMenu::addObserver(Observer* p_observer)
{
	m_observers[0] = nullptr;
	m_observers[0] = p_observer;
	m_numObservers++;
}
