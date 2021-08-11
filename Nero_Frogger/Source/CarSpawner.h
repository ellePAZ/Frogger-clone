#pragma once
#include "Subject.h"
#include <time.h>
#include "Vehicle.h"
#include "Event.h"
#include "SFML/Audio.hpp"

class CarSpawner : public Subject, public Entity
{
private:
	sf::Clock m_clock;

	float m_interval = 0;
	float m_minTime = 1.f;
	float m_maxTime = 10.f;
	const float m_origMinTime = m_minTime;
	const float m_origMaxTime = m_maxTime;

	Vehicle* m_prototype;

	bool m_isSpawning = true;


public:
	CarSpawner(Vehicle*, sf::Vector2f p_startPos);
	~CarSpawner();

	void update(float);

	void setPrototype(Vehicle* p_prototype);

	void decreaseMinMax(float p_divisor);
	void doubleMin();
	void resetSpawnRate();

	void setSpawning(bool p_isSpawning);
};