#pragma once

#include "GameManager.h"
#include "AIPaddle.h"
#include "PlayerPaddle.h"
#include "Ball.h"
class PongManager : virtual public GameManager
{
protected:
	std::vector<std::shared_ptr<Paddle>> paddles;
	std::shared_ptr<Ball> ball;

	int team1Score;
	int team2Score;
public:
	PongManager();
	~PongManager();

	virtual void Initialize();
	virtual void Start();

	void Score(bool team1);
	bool CheckWin();
};