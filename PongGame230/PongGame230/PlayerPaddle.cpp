#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle()
{
	upKey = sf::Keyboard::W;
	downKey = sf::Keyboard::S;
	leftKey = sf::Keyboard::A;
	rightKey = sf::Keyboard::D;
}
PlayerPaddle::PlayerPaddle(sf::RenderWindow* win, float X, float Y, float W, float H, int pID, bool isVert)
	: Paddle(win,X,Y,W,H,pID,isVert),
	  GameObject(win,X,Y,W,H,true)
{
	if (pID == 0)
	{
		upKey = sf::Keyboard::W;
		downKey = sf::Keyboard::S;
		leftKey = sf::Keyboard::A;
		rightKey = sf::Keyboard::D;
	}
	else if (pID == 1)
	{
		upKey = sf::Keyboard::Up;
		downKey = sf::Keyboard::Down;
		leftKey = sf::Keyboard::Left;
		rightKey = sf::Keyboard::Right;
	}
}
PlayerPaddle::PlayerPaddle(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, int pID, bool isVert)
	: Paddle(win,pos,W,H,pID,isVert),
	  GameObject(win,pos,W,H,true)
{
	if (pID == 0)
	{
		upKey = sf::Keyboard::W;
		downKey = sf::Keyboard::S;
		leftKey = sf::Keyboard::A;
		rightKey = sf::Keyboard::D;
	}
	else if (pID == 1)
	{
		upKey = sf::Keyboard::Up;
		downKey = sf::Keyboard::Down;
		leftKey = sf::Keyboard::Left;
		rightKey = sf::Keyboard::Right;
	}
}
PlayerPaddle::~PlayerPaddle()
{}

void PlayerPaddle::ReadControls()
{
	if (isVertical)
	{
		bool up = sf::Keyboard::isKeyPressed(upKey);
		bool down = sf::Keyboard::isKeyPressed(downKey);

		if (up && !down)
		{	this->MovePositive();	}
		else if (!up && down)
		{	this->MoveNegative();	}
		else
		{	this->MoveNeutral();	}
	}
	else
	{
		bool right = sf::Keyboard::isKeyPressed(rightKey);
		bool left = sf::Keyboard::isKeyPressed(leftKey);

		if (right && !left)
		{	this->MovePositive();	}
		else if (!right && left)
		{	this->MoveNegative();	}
		else
		{	this->MoveNeutral();	}
	}
}

void PlayerPaddle::Update(float deltaTime)
{
	this->ReadControls();

	//Paddle::Update(deltaTime);
}