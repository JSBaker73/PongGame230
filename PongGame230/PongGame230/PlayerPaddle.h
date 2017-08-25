#pragma once

#include <SFML\Window\Keyboard.hpp>
#include "Paddle.h"
class PlayerPaddle : virtual public Paddle
{
protected:
	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key rightKey;
public:
	PlayerPaddle();
	PlayerPaddle(sf::RenderWindow* win, float X, float Y, float W, float H, int pID, bool isVert);
	PlayerPaddle(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, int pID, bool isVert);
	~PlayerPaddle();

	void ReadControls();

	virtual void Update(float deltaTime);
};

