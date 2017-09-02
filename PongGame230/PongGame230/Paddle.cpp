#include "Paddle.h"
#include "GameManager.h"
#include <cmath>

Paddle::Paddle()
{
	paddle.setSize(sf::Vector2f(0, 0));
	paddle.setPosition(sf::Vector2f(0, 0));
	paddle.setFillColor(sf::Color::White);

	playerID = -1;
	isVertical = true;
}
Paddle::Paddle(sf::RenderWindow* win, GameManager* man, float X, float Y, float W, float H, int pID, bool isVert)
	: GameObject(win,man,X,Y,W,H,true)
{
	paddle.setSize(sf::Vector2f(W, H));
	paddle.setPosition(sf::Vector2f(X, Y));
	paddle.setOrigin(sf::Vector2f(W / 2, H / 2));
	this->SetAnchor(paddle.getOrigin());
	paddle.setFillColor(sf::Color::White);

	playerID = pID;
	isVertical = isVert;
}
Paddle::Paddle(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float W, float H, int pID, bool isVert)
	: GameObject(win,man,pos,W,H,true)
{
	paddle.setSize(sf::Vector2f(W, H));
	paddle.setPosition(pos);
	paddle.setOrigin(sf::Vector2f(W / 2, H / 2));
	this->SetAnchor(paddle.getOrigin());
	paddle.setFillColor(sf::Color::White);

	playerID = pID;
	isVertical = isVert;
}
Paddle::~Paddle()
{}

inline int Paddle::GetPlayerID()
{	return playerID;	}
void Paddle::SetPlayerID(int newID)
{	playerID = newID;	}

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

void Paddle::CheckHit(Ball* ball)
{
	sf::FloatRect* other = new sf::FloatRect(GameObject::GetRect(this));
	other->left -= ball->GetRadius();
	other->top -= ball->GetRadius();
	other->width += 2 * ball->GetRadius();
	other->height += 2 * ball->GetRadius();

	if (other->contains(ball->GetPosition()))
	{
		delete other;
		other = new sf::FloatRect(GameObject::GetRect(ball));
		this->Hit(ball, other);
		delete other;
		return;
	}
	delete other;
}
void Paddle::Hit(GameObject* other, sf::FloatRect* rect)
{
	if (rect == NULL)
	{
		sf::Vector2f oldVel = other->GetVelocity();
		float speed = std::sqrtf(std::powf(oldVel.y,2.f) + std::powf(oldVel.x,2.f));
		float posRatio = (other->GetPosition().y - this->GetPosition().y)/(this->getHeight()/2);
		float angle = (posRatio * 60)*PI / 180;
		posRatio = (posRatio > 1 ? 1 : (posRatio < -1 ? -1 : posRatio));
		speed += 73 * (1 - std::abs(posRatio));
		oldVel.x = (oldVel.x < 0 ? -std::cos(angle) * speed : oldVel.x = std::cos(angle) * speed);
		oldVel.y = (oldVel.y < 0 ? std::sin(angle) * speed : oldVel.y = std::sin(angle) * speed);
		other->SetVelocity(oldVel);
	}
	else
	{
		if (oldPosition.x + width - anchor.x < rect->left && position.x + width - anchor.x >= rect->left)
		{
			Ball* ball = dynamic_cast<Ball*>(other);
			ball->Bounce(false, false, sf::Vector2f(position.x + width - anchor.x, -1));
			this->Hit(ball, NULL);
		}
		else if (oldPosition.x - anchor.x > rect->left + rect->width && position.x - anchor.x <= rect->left + rect->width)
		{
			Ball* ball = dynamic_cast<Ball*>(other);
			ball->Bounce(false, true, sf::Vector2f(position.x - anchor.x, -1));
			this->Hit(ball, NULL);
		}

		if (oldPosition.y + height - anchor.y < rect->top && position.y + height - anchor.y >= rect->top)
		{
			Ball* ball = dynamic_cast<Ball*>(other);
			ball->Bounce(true, false, sf::Vector2f(-1, position.y + height - anchor.y));
			this->Hit(ball, NULL);
		}
		else if (oldPosition.y - anchor.y > rect->top + rect->height && position.y - anchor.y <= rect->top + rect->height)
		{
			Ball* ball = dynamic_cast<Ball*>(other);
			ball->Bounce(true, true, sf::Vector2f(-1, position.y - anchor.y));
			this->Hit(ball, NULL);
		}
	}
}

void Paddle::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	std::vector<GameObject*> collisisions = std::vector<GameObject*>(this->manager->GetCollisions(this));
	if (collisisions.size() > 0)
	{
		for (auto it = collisisions.begin(); it != collisisions.end(); ++it)
		{
			try
			{
				Ball* hitBall = dynamic_cast<Ball*>(collisisions.at(std::distance(collisisions.begin(), it)));
				CheckHit(hitBall);
			}
			catch(const std::bad_cast& e)
			{}
		}
	}
	
	bool* hits = new bool[4];
	for (int i = 0; i < 4; ++i) { hits[i] = false; }

	this->Collide(window, hits);

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
{
	int a = 0;
	sf::Vector2f pos = paddle.getPosition();
	window->draw(paddle);
}