#pragma once

#include <SFML\Graphics\CircleShape.hpp>
#include "GameObject.h"
class Ball : public GameObject
{
protected:
	sf::CircleShape ball;

	const float PI = 3.14159f;
	const float sqrtTwo = std::sqrtf(2.f);
	const float startSpeed = 150.f;
	bool isActive;
public:
	Ball();
	Ball(sf::RenderWindow* win, GameManager* man, float X, float Y, float R);
	Ball(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float R);
	~Ball();

	float GetRadius();
	float GetStartSpeed();
	bool IsActive();

	void Start(float angle);
	void Stop();
	void CheckHit(GameObject* obj);
	virtual void Hit(GameObject* other, sf::FloatRect* rect);
	void Bounce(bool hitHorizontal, bool positiveSide, sf::Vector2f hitPos);

	virtual void Update(float deltaTime);
	virtual void Draw();
};

