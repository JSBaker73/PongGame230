#include "Ball.h"
#include "GameManager.h"

Ball::Ball()
{
	ball.setRadius(0);
	ball.setPosition(0, 0);
	ball.setFillColor(sf::Color::White);

	isActive = false;
}
Ball::Ball(sf::RenderWindow* win, GameManager* man, float X, float Y, float R)
	: GameObject(win,man,X,Y,R*2,R*2,true)
{
	ball.setRadius(R);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(sf::Vector2f(X, Y));
	ball.setOrigin(sf::Vector2f(R, R));
	this->SetAnchor(ball.getOrigin());

	isActive = false;
}
Ball::Ball(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float R)
	: GameObject(win,man,pos,R*2,R*2,true)
{
	ball.setRadius(R);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(pos);
	ball.setOrigin(sf::Vector2f(R, R));
	this->SetAnchor(ball.getOrigin());

	isActive = false;
}
Ball::~Ball()
{}

float Ball::GetRadius()
{	return ball.getRadius();	}
float Ball::GetStartSpeed()
{	return startSpeed;	}
bool Ball::IsActive()
{	return isActive;	}

void Ball::Start(float angle)
{
	isActive = true;

	this->SetVelocity(sf::Vector2f(std::cos(angle*PI/180.f)*startSpeed, std::sin(angle*PI/180.f)*startSpeed));
}
void Ball::Stop()
{	manager->Stop();	}
void Ball::CheckHit(GameObject* obj)
{
	sf::FloatRect* other = new sf::FloatRect(GameObject::GetRect(obj));
	other->left -= ball.getRadius();
	other->top -= ball.getRadius();
	other->width += 2 * ball.getRadius();
	other->height += 2 * ball.getRadius();

	if (other->contains(position))
	{
		this->Hit(obj, other);
		delete other;
		return;
	}
	delete other;
}
void Ball::Hit(GameObject* other, sf::FloatRect* rect)
{
	if (rect != NULL)
	{
		if (oldPosition.x < rect->left && position.x >= rect->left)
		{
			delete rect;

			rect = new sf::FloatRect(GameObject::GetRect(other));
			Bounce(false, true, sf::Vector2f(rect->left, -1));
			other->Hit(this, NULL);
		}
		else if (oldPosition.x > rect->left + rect->width && position.x <= rect->left + rect->width)
		{
			rect = new sf::FloatRect(GameObject::GetRect(other));
			Bounce(false, false, sf::Vector2f(rect->left + rect->width, -1));
			other->Hit(this, NULL);
		}

		if (oldPosition.y < rect->top && position.y >= rect->top)
		{
			rect = new sf::FloatRect(GameObject::GetRect(other));
			Bounce(true, true, sf::Vector2f(-1, rect->top));
			other->Hit(this, NULL);
		}
		else if (oldPosition.y > rect->top + rect->height && position.y <= rect->top + rect->height)
		{
			rect = new sf::FloatRect(GameObject::GetRect(other));
			Bounce(true, false, sf::Vector2f(-1, rect->top + rect->height));
			other->Hit(this, NULL);
		}
	}
	
	if (oldPosition.y < rect->top && position.y >= rect->top)
	{
		rect = new sf::FloatRect(GameObject::GetRect(other));
		Bounce(true, true, sf::Vector2f(-1, rect->top));
		other->Hit(this, NULL);
	}
	else if (oldPosition.y > rect->top + rect->height && position.y <= rect->top + rect->height)
	{
		rect = new sf::FloatRect(GameObject::GetRect(other));
		Bounce(true, false, sf::Vector2f(-1, rect->top + rect->height));
		other->Hit(this, NULL);
	}
}
void Ball::Bounce(bool hitHorizontal, bool positiveSide, sf::Vector2f hitPos)
{
	if (hitHorizontal)
	{
 		this->SetPosition(sf::Vector2f(this->GetPosition().x, (hitPos.y + (positiveSide ? anchor.y - height : anchor.y))));
		this->SetVelocity(sf::Vector2f(this->GetVelocity().x, std::abs(this->GetVelocity().y) * (positiveSide ? -1.f : 1.f)));
	}
	else
	{
		this->SetPosition(sf::Vector2f((hitPos.x + (positiveSide ? anchor.x - width : anchor.x)), this->GetPosition().y));
		this->SetVelocity(sf::Vector2f(std::abs(this->GetVelocity().x) * (positiveSide ? -1.f : 1.f), this->GetVelocity().y));
	}
}

void Ball::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	std::vector<GameObject*> collisisions = std::vector<GameObject*>(this->manager->GetCollisions(this));
	if (collisisions.size() > 0)
	{
		for (auto it = collisisions.begin(); it != collisisions.end(); ++it)
		{	CheckHit(collisisions.at(std::distance(collisisions.begin(), it)));	}
	}

	bool* hits = new bool[4];
	for (int i = 0; i < 4; ++i) { hits[i] = false; }
	this->Collide(window, hits);

	if (hits[0])
	{	this->Stop();	}
//	this->Bounce(false, false, sf::Vector2f(0,-1));
	else if (hits[1])
	{	this->Stop();	}
//	this->Bounce(false, true, sf::Vector2f((float)window->getSize().x,-1));
	else if (hits[2])
	{	this->Bounce(true, false, sf::Vector2f(-1,0));	}
	else if (hits[3])
	{	this->Bounce(true, true, sf::Vector2f(-1,(float)window->getSize().y));	}

	delete[] hits;
	hits = NULL;

	ball.setPosition(position);
	int a = 0;
}
void Ball::Draw()
{	window->draw(ball);	}
