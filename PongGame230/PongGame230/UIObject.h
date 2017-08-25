#pragma once

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

class UIObject
{
protected:
	sf::RenderWindow* window;

	sf::Vector2f position;
	sf::Vector2f anchor;

	float width;
	float height;
	bool clickable;
	bool toBeDeleted;
public:
	UIObject();
	UIObject(sf::RenderWindow* win, float X, float Y, float W, float H);
	UIObject(sf::RenderWindow* win, sf::Vector2f pos, float W, float H);
	~UIObject();

	sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f newPos);
	sf::Vector2f GetAnchor();
	virtual void SetAnchor(sf::Vector2f newAnc);

	float GetWidth();
	float GetHeight();
	bool GetClickable();
	bool GetToBeDeleted();

	static sf::FloatRect GetRect(UIObject* obj);
	virtual bool ContainsPoint(sf::Vector2f point);

	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
	virtual void Delete();
};

