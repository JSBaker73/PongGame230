#include "UIObject.h"

UIObject::UIObject()
{
	window = NULL;

	position = sf::Vector2f(0, 0);
	anchor = sf::Vector2f(0, 0);

	width = 0;
	height = 0;
	visible = true;
	clickable = false;
}
UIObject::UIObject(sf::RenderWindow* win, float X, float Y, float W, float H)
{
	window = win;

	position = sf::Vector2f(X, Y);
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	visible = true;
	clickable = false;
}
UIObject::UIObject(sf::RenderWindow* win, sf::Vector2f pos, float W, float H)
{
	window = win;

	position = pos;
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	visible = true;
	clickable = false;
}
UIObject::~UIObject()
{}

sf::Vector2f UIObject::GetPosition()
{	return position;	}
void UIObject::SetPosition(sf::Vector2f newPos)
{	position = newPos;	}
sf::Vector2f UIObject::GetAnchor()
{	return anchor;	}
void UIObject::SetAnchor(sf::Vector2f newAnc)
{	anchor = newAnc;	}

float UIObject::GetWidth()
{	return width;	}
float UIObject::GetHeight()
{	return height;	}
bool UIObject::GetVisible()
{	return visible;	}
void UIObject::SetVisible(bool isVisible)
{	this->visible = isVisible;	}
bool UIObject::GetClickable()
{	return clickable;	}

sf::FloatRect UIObject::GetRect(UIObject* obj)
{
	float left = obj->position.x - obj->anchor.x;
	float top = obj->position.y - obj->anchor.y;

	return sf::FloatRect(left, top, obj->width, obj->height);
}
bool UIObject::ContainsPoint(sf::Vector2f point)
{	return UIObject::GetRect(this).contains(point);	}