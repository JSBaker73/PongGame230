#pragma once

#include <SFML\System\Time.hpp>
#include "Paddle.h"
#include "Ball.h"
class AIPaddle : virtual public Paddle
{
protected:
	sf::Clock AITimer;
	const sf::Time AITime = sf::seconds(.1f);

	Ball* ball;
public:
	AIPaddle();
	AIPaddle(sf::RenderWindow* win, float X, float Y, float W, float H, int pID, bool isVert, Ball* theBall);
	AIPaddle(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, int pID, bool isVert, Ball* theBall);
	~AIPaddle();

	void AIMove();

	virtual void Update(float deltaTime);
};

