#include "Paddle.h"

Paddle::Paddle()
{
	paddle.setSize(sf::Vector2f(0, 0));
	paddle.setPosition(sf::Vector2f(0, 0));
	paddle.setFillColor(sf::Color::White);

	playerID = -1;
	isVertical = true;
}
Paddle::Paddle(sf::RenderWindow* win, float X, float Y, float W, float H, int pID, bool isVert)
	: GameObject(win, X, Y, W, H, true)
{
	paddle.setSize(sf::Vector2f(W, H));
	paddle.setPosition(sf::Vector2f(X, Y));
	paddle.setFillColor(sf::Color::White);
	paddle.setOrigin(sf::Vector2f(W / 2, H / 2));
	this->SetAnchor(paddle.getOrigin());

	playerID = pID;
	isVertical = isVert;
}
Paddle::Paddle(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, int pID, bool isVert)
	: GameObject(win, pos, W, H, true)
{
	paddle.setSize(sf::Vector2f(W, H));
	paddle.setPosition(pos);
	paddle.setFillColor(sf::Color::White);
	paddle.setOrigin(sf::Vector2f(W / 2, H / 2));
	this->SetAnchor(paddle.getOrigin());

	playerID = pID;
	isVertical = isVert;
}
Paddle::~Paddle()
{}

inline int Paddle::GetPlayerID()
{	return playerID;	}
//void Paddle::SetPlayerID(int newID)
//{	playerID = newID;	}

void Paddle::MovePositive()
{
	// Moving Up
	if (isVertical)
	{	this->SetVelocity(sf::Vector2f(0, -speed));	}
	// Moving Right
	else
	{	this->SetVelocity(sf::Vector2f(speed, 0));	}
}
void Paddle::MoveNeutral()
{	this->SetVelocity(sf::Vector2f(0, 0));	}
void Paddle::MoveNegative()
{
	// Moving Down
	if (isVertical)
	{	this->SetVelocity(sf::Vector2f(0, speed));	}
	// Moving Left
	else
	{	this->SetVelocity(sf::Vector2f(-speed, 0));	}
}

void Paddle::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	bool* hits = this->Collide(window);

	if (hits[0])
	{	this->SetPosition(sf::Vector2f(anchor.x, position.y));	}
	else if (hits[1])
	{	this->SetPosition(sf::Vector2f(window->getSize().x - (width - anchor.x), position.y));	}
	if (hits[2])
	{	this->SetPosition(sf::Vector2f(position.x, anchor.y));	}
	else if (hits[3])
	{	this->SetPosition(sf::Vector2f(position.x, window->getSize().y - (height - anchor.y)));	}

	delete[] hits;
	hits = NULL;

	paddle.setPosition(position);
}
void Paddle::Draw()
{	window->draw(paddle);	}