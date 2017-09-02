#include "AIPaddle.h"
#include "PongManager.h"

AIPaddle::AIPaddle()
{	started = false;	}
AIPaddle::AIPaddle(sf::RenderWindow* win, GameManager* man, float X, float Y, float W, float H, int pID, bool isVert)
	: Paddle(win,man,X,Y,W,H,pID,isVert)
{	started = false;	}
AIPaddle::AIPaddle(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float W, float H, int pID, bool isVert)
	: Paddle(win,man,pos,W,H,pID,isVert)
{	started = false;	}
AIPaddle::~AIPaddle()
{}

void AIPaddle::Start()
{
	try
	{
		PongManager* pongManager = dynamic_cast<PongManager*>(manager);
		ball = pongManager->GetBall();
		started = true;
	}
	catch (const std::bad_cast& e)
	{}
}
void AIPaddle::Stop()
{	started = false;	}

void AIPaddle::AIMove()
{
	if (AITimer.getElapsedTime() >= AITime)
	{
		AITimer.restart();

		if (isVertical)
		{
			float ratio = std::abs(ball->GetPosition().x - position.x) / ((float)(window->getSize().x - 50));
			if (ball->GetPosition().y < (this->GetPosition().y - height * (1 + ratio) / 4))
			{	this->MovePositive();	}
			else if (ball->GetPosition().y > (this->GetPosition().y + height * (1 + ratio) / 4))
			{	this->MoveNegative();	}
			else
			{	this->MoveNeutral();	}
		}
		else
		{
			if (ball->GetPosition().x > (this->GetPosition().x - width / 4))
			{	this->MovePositive();	}
			else if (ball->GetPosition().x <(this->GetPosition().x + width / 4))
			{	this->MoveNegative();	}
			else
			{	this->MoveNeutral();	}
		}
	}
}

void AIPaddle::Update(float deltaTime)
{
	if (started)
	{	AIMove();	}
	else
	{	this->MoveNeutral();	}

	Paddle::Update(deltaTime);
}