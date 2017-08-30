#include "Ball.h"

Ball::Ball()
{
	ball.setRadius(0);
	ball.setPosition(0, 0);
	ball.setFillColor(sf::Color::White);

	isActive = false;
}
Ball::Ball(sf::RenderWindow* win, float X, float Y, float R)
	: GameObject(win, X, Y, R * 2, R * 2, true)
{
	ball.setRadius(R-2);
	ball.setOutlineThickness(2);
	ball.setOutlineColor(sf::Color::Black);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(sf::Vector2f(X, Y));
	ball.setOrigin(sf::Vector2f(R, R));
	this->SetAnchor(ball.getOrigin());

	isActive = false;
}
Ball::Ball(sf::RenderWindow* win, sf::Vector2f pos, float R)
	: GameObject(win, pos, R * 2, R * 2, true)
{
	ball.setRadius(R - 3);
	ball.setOutlineThickness(3);
	ball.setOutlineColor(sf::Color::Black);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(pos);
	ball.setOrigin(sf::Vector2f(R, R));
	this->SetAnchor(ball.getOrigin());

	isActive = false;
}
Ball::~Ball()
{}

float Ball::GetStartSpeed()
{	return startSpeed;	}
bool Ball::IsActive()
{	return isActive;	}

void Ball::Start(float angle)
{
	isActive = true;

	this->SetVelocity(sf::Vector2f(std::cos(angle)*startSpeed, std::sin(angle)*startSpeed));
}
void Ball::CheckHit(GameObject* obj)
{

}
void Ball::Hit(GameObject* other)
{

}
void Ball::Bounce(bool hitHorizontal)
{
	if (hitHorizontal)
	{	this->SetVelocity(sf::Vector2f(this->GetVelocity().x, -this->GetVelocity().y));	}
	else
	{	this->SetVelocity(sf::Vector2f(this->GetVelocity().x, -this->GetVelocity().y));	}
}

void Ball::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}
void Ball::Draw()
{	window->draw(ball);	}
