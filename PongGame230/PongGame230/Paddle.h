#pragma once

#include <SFML\Graphics\RectangleShape.hpp>
#include "GameObject.h"
#include "Ball.h"
class Paddle : public GameObject
{
protected:
	sf::RectangleShape paddle;

	const float PI = 3.14159f;
	const float speed = 200.f;
	int playerID;
	bool isVertical;
public:
	Paddle();
	Paddle(sf::RenderWindow* win, GameManager* man, float X, float Y, float W, float H, int pID, bool isVert);
	Paddle(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float W, float H, int pID, bool isVert);
	virtual ~Paddle();

	int GetPlayerID();
	void SetPlayerID(int newID);

	void MovePositive();
	void MoveNeutral();
	void MoveNegative();

	void CheckHit(Ball* ball);
	virtual void Hit(GameObject* other, sf::FloatRect* rect);

	virtual void Update(float deltaTime);
	virtual void Draw();
};

