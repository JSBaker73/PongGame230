#pragma once

#include <SFML\Graphics\CircleShape.hpp>
#include "GameObject.h"
class Ball : virtual public GameObject
{
protected:
	sf::CircleShape ball;

	const float PI = 3.14159f;
	const float startSpeed = 10;
	bool isActive;
public:
	Ball();
	Ball(sf::RenderWindow* win, float X, float Y, float R);
	Ball(sf::RenderWindow* win, sf::Vector2f pos, float R);
	~Ball();

	float GetStartSpeed();

	void Start(float angle);
	void CheckHit(GameObject* obj);
	virtual void Hit(GameObject* other);
	void Bounce(bool hitHorizontal);

	virtual void Update(float deltaTime);
	virtual void Draw();
};

