#include "PongManager.h"

PongManager::PongManager()
{
	team1Score = 0;
	team2Score = 0;
}
PongManager::~PongManager()
{}

void PongManager::Initialize()
{
	ball = std::make_shared<Ball>(window, (static_cast<sf::Vector2f>(window->getSize())/2.f),10.f);
}
void PongManager::Start()
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

}
bool PongManager::CheckWin()
{
	return false;
}