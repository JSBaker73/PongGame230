#pragma once

#include "GameManager.h"
#include "UILabel.h"
#include "AIPaddle.h"
#include "PlayerPaddle.h"
#include "Ball.h"

class PongState;

class PongManager : public GameManager
{
protected:
	std::vector<std::shared_ptr<Paddle>> paddles;
	std::shared_ptr<Ball> ball;

	std::shared_ptr<UILabel> team1Label;
	std::shared_ptr<UILabel> team1ScoreLabel;
	std::shared_ptr<UILabel> team2Label;
	std::shared_ptr<UILabel> team2ScoreLabel;
	std::shared_ptr<UILabel> startText;
	std::shared_ptr<UILabel> exitText;

	std::vector<std::shared_ptr<UILabel>> winMessages;
	std::vector<std::shared_ptr<UILabel>> instructions;

	PongState* PS;
	int team1Score;
	int team2Score;
public:
	PongManager();
	PongManager(sf::RenderWindow* win, PongState* pongState);
	~PongManager();

	Ball* GetBall();
	bool GetBallActive();

	virtual void Initialize();
	virtual void Start();
	virtual void Stop();
	virtual void End();
	void ShootBall();

	void Score(bool team1);
	bool CheckWin();
};