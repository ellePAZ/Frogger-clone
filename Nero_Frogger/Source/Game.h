#pragma once

#include "SFML/Graphics.hpp"
#include "Frog.h"
#include "Grid.h"
#include "Car.h"
#include "CarFast.h"
#include "Truck.h"
#include "CarSlow.h"
#include "CarHotDog.h"
#include "Observer.h"
#include "Event.h"
#include "CarSpawner.h"
#include "Log.h"
#include "Gui.h"
#include "StartMenu.h"

class Game : public Observer
{
public:
	Game(unsigned int &screenWidth, unsigned int &screenHeight, const char* &title);
	~Game();
	/// Return Value
	/// true = Continue to run program
	/// false = Quits program
	bool Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	virtual void onNotify(Entity* entity, Event event);
	virtual void onNotify(Event event);

	bool checkCollisionToCars();
	bool checkCollisionToWater();
	void checkCollisionToGoal();
	void checkCollisionToDeleter();

	void damageFrog();
	void frogInGoal(float xPos);

	void nextLevel();	
	void restartGame();

private:
	Frog* m_frog;
	Grid* m_grid;

	std::vector<Vehicle*> m_cars;
	Vehicle* m_carTemplates[5];
	CarSpawner* m_carSpawner[5];
	Vehicle* m_spawnerPrototype[5];
	Log* m_log[10];

	Gui m_gui;
	StartMenu* m_startMenu;

	sf::VertexArray m_water;

	Frog* m_goalFrog[6]{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

	float m_cutoffPoint;
	float m_cutoffPoint2;

	sf::Vector2i m_screenSize;

	unsigned int m_goalCounter = 0;
	unsigned int m_levelCounter = 0;

	std::vector<sf::RectangleShape*> m_grassRect;
	std::vector<sf::RectangleShape*> m_waterRect;

	sf::RectangleShape m_deleter[2];

	sf::SoundBuffer m_splashBuffer;
	sf::Sound m_splashSound;

	sf::SoundBuffer m_squashBuffer;
	sf::Sound m_squashSound;

};