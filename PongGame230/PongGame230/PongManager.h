#pragma once

#include "GameManager.h"
#include "AIPaddle.h"
#include "PlayerPaddle.h"
#include "Ball.h"

class PongState;

class PongManager : virtual public GameManager
{
protected:
	std::vector<std::shared_ptr<Paddle>> paddles;
	std::shared_ptr<Ball> ball;

	PongState* PS;
	int team1Score;
	int team2Score;
public:
	PongManager();
	PongManager(sf::RenderWindow* win, PongState* pongState);
	~PongManager();

	bool GetBallActive();

	virtual void Initialize();
	virtual void Start();
	virtual void End();
	void ShootBall();

	void Score(bool team1);
	bool CheckWin();
};