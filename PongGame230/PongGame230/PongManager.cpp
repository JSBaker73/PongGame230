#include "PongManager.h"

#include "PongState.h"
PongManager::PongManager()
{
	team1Score = 0;
	team2Score = 0;
}
PongManager::PongManager(sf::RenderWindow* win, PongState* pongState)
	: GameManager(win)
{
	PS = pongState;
	team1Score = 0;
	team2Score = 0;
}
PongManager::~PongManager()
{}

bool PongManager::GetBallActive()
{	return ball->IsActive();	}

void PongManager::Initialize()
{
	ball = std::make_shared<Ball>(window, (static_cast<sf::Vector2f>(window->getSize()) / 2.f), 10.f);
	this->AddGameObject(ball);
	
	switch (PS->GetGameMode())
	{
	case GameMode::PVP:
		paddles.push_back(std::make_shared<PlayerPaddle>(window, 20.f, (float)(window->getSize().y) / 2, 25.f, 100.f, 0, true));
		paddles.push_back(std::make_shared<PlayerPaddle>(window, (float)(window->getSize().x) - 20, (float)(window->getSize().y) / 2, 25.f, 100.f, 1, true));
		break;
	case GameMode::PVAI:
		break;
	case GameMode::TVT:
		break;
	default:
		break;
	}
	for (auto it = paddles.begin(); it != paddles.end(); ++it)
	{
		int index = std::distance(paddles.begin(), it);
		this->AddGameObject(paddles.at(index));
	}
}
void PongManager::Start()
{
	started = true;

	this->ShootBall();
}
void PongManager::End()
{	ended = true;	}
void PongManager::ShootBall()
{
	float angle = (float)(std::rand() % 180);
	if (angle < 90)
	{	angle -= 45;	}
	else
	{	angle += 45;	}

	ball->Start(angle);
}

void PongManager::Score(bool team1)
{
	if (team1)
	{	team1Score += 1;	}
	else
	{	team2Score += 1;	}

	if (this->CheckWin())
	{	this->End();	}
}
bool PongManager::CheckWin()
{
	if (team1Score >= 5 || team2Score >= 5)
	{	return true;	}
	else
	{	return false;	}
}