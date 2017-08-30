#pragma once

#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\Text.hpp>
#include "UIObject.h"
class UIButton : virtual public UIObject
{
protected:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text label;

public:
	UIButton();
	UIButton(sf::RenderWindow* win, float X, float Y, float W, float H, std::string text);
	UIButton(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, std::string text);
	~UIButton();

	virtual void SetPosition(sf::Vector2f newPos);
	virtual void SetAnchor(sf::Vector2f newAnc);

	virtual void Update(float deltaTime);
	virtual void Draw();
	virtual void Delete();
};

