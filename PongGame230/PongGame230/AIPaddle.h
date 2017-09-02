#pragma once

#include <SFML\System\Time.hpp>
#include "Paddle.h"
#include "Ball.h"
class AIPaddle : public Paddle
{
protected:
	sf::Clock AITimer;
	const sf::Time AITime = sf::seconds(.25f);

	Ball* ball;
	bool started;
public:
	AIPaddle();
	AIPaddle(sf::RenderWindow* win, GameManager* man, float X, float Y, float W, float H, int pID, bool isVert);
	AIPaddle(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float W, float H, int pID, bool isVert);
	~AIPaddle();

	void Start();
	void Stop();

	void AIMove();

	virtual void Update(float deltaTime);
};

