#pragma once

#include <SFML\Graphics\RectangleShape.hpp>
#include "GameObject.h"
class Paddle : virtual public GameObject
{
protected:
	sf::RectangleShape paddle;

	const float speed = 10;
	int playerID;
	bool isVertical;
public:
	Paddle();
	Paddle(sf::RenderWindow* win, float X, float Y, float W, float H, int pID, bool isVert);
	Paddle(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, int pID, bool isVert);
	virtual ~Paddle();

	int GetPlayerID();
	//void SetPlayerID(int newID);

	void MovePositive();
	void MoveNeutral();
	void MoveNegative();

	virtual void Update(float deltaTime);
	virtual void Draw();
};

