#pragma once
#include "Entity.h"
#include "Subject.h"

class Log : public Entity, public Subject
{
private:
	int m_length = 1;
	
	float m_moveSpeed = 50;
	float m_originalSpeed;
	
	int m_endPoint = -100;
	int m_spawnPoint = -100;

	bool m_goingLeft = false;

public:
	Log(int p_size, int p_length, sf::Vector2f p_startPos, float p_moveSpeed);
	~Log();

	virtual void update(float);

	virtual sf::FloatRect getShapeBounds();
	
	float getMoveSpeed();
	void resetSpeed();

	void increaseMoveSpeed(float p_moveSpeed);
};