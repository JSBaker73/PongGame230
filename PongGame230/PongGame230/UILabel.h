#pragma once

#include <SFML\Graphics\Text.hpp>
#include "UIObject.h"
class UILabel : public UIObject
{
protected:
	sf::Font font;
	sf::Text label;
public:
	UILabel();
	UILabel(sf::RenderWindow* win, float X, float Y, int size, std::string text);
	UILabel(sf::RenderWindow* win, sf::Vector2f pos, int size, std::string text);
	~UILabel();

	int GetSize();
	void SetSize(int size);
	std::string GetText();
	void SetText(std::string text);

	virtual void Update(float deltaTime);
	virtual void Draw();
};

