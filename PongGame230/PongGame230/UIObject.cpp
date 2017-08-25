#include "UIObject.h"

UIObject::UIObject()
{
	window = NULL;

	position = sf::Vector2f(0, 0);
	anchor = sf::Vector2f(0, 0);

	width = 0;
	height = 0;
	clickable = false;
	toBeDeleted = false;
}
UIObject::UIObject(sf::RenderWindow* win, float X, float Y, float W, float H)
{
	window = win;

	position = sf::Vector2f(X, Y);
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	clickable = false;
	toBeDeleted = false;
}
UIObject::UIObject(sf::RenderWindow* win, sf::Vector2f pos, float W, float H)
{
	window = win;

	position = pos;
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	clickable = false;
	toBeDeleted = false;
}
UIObject::~UIObject()
{}

inline sf::Vector2f UIObject::GetPosition()
{	return position;	}
void UIObject::SetPosition(sf::Vector2f newPos)
{	position = newPos;	}
sf::Vector2f UIObject::GetAnchor()
{	return anchor;	}
void UIObject::SetAnchor(sf::Vector2f newAnc)
{
	position -= anchor;
	anchor = newAnc;
	position += anchor;
}

float UIObject::GetWidth()
{	return width;	}
float UIObject::GetHeight()
{	return height;	}
bool UIObject::GetClickable()
{	return clickable;	}
inline bool UIObject::GetToBeDeleted()
{	return toBeDeleted;	}
sf::FloatRect UIObject::GetRect(UIObject* obj)
{
	float left = obj->position.x - obj->anchor.x;
	float top = obj->position.y - obj->anchor.y;

	return sf::FloatRect(left, top, obj->width, obj->height);
}
bool UIObject::ContainsPoint(sf::Vector2f point)
{	return UIObject::GetRect(this).contains(point);	}

void UIObject::Delete()
{	toBeDeleted = true;	}