#include "AIPaddle.h"

AIPaddle::AIPaddle()
{}
AIPaddle::AIPaddle(sf::RenderWindow* win, float X, float Y, float W, float H, int pID, bool isVert, Ball* theBall)
	: Paddle(win,X,Y,W,H,pID,isVert),
	  GameObject(win, X, Y, W, H, true)
{	ball = theBall;	}
AIPaddle::AIPaddle(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, int pID, bool isVert, Ball* theBall)
	: Paddle(win, pos, W, H, pID, isVert),
	  GameObject(win, pos, W, H, true)
{	ball = theBall;	}
AIPaddle::~AIPaddle()
{}

void AIPaddle::AIMove()
{
	if (AITimer.getElapsedTime() >= AITime)
	{
		AITimer.restart();

		if (isVertical)
		{
			if (ball->GetPosition().y < (this->GetPosition().y - height / 4))
			{	this->MovePositive();	}
			else if (ball->GetPosition().y > (this->GetPosition().y + height / 4))
			{	this->MoveNegative();	}
		}
		else
		{
			if (ball->GetPosition().x > (this->GetPosition().x - width / 4))
			{	this->MovePositive();	}
			else if (ball->GetPosition().x <(this->GetPosition().x + width / 4))
			{	this->MoveNegative();	}
		}
	}
}

void AIPaddle::Update(float deltaTime)
{
	AIMove();

	Paddle::Update(deltaTime);
}