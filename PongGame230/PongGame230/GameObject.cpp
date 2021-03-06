#include "GameObject.h"
#include "GameManager.h"

GameObject::GameObject()
{
	window = NULL;
	manager = NULL;

	position = sf::Vector2f(0, 0);
	velocity = sf::Vector2f(0, 0);
	anchor = sf::Vector2f(0, 0);

	width = 0;
	height = 0;
	collides = false;
}
GameObject::GameObject(sf::RenderWindow* win, GameManager* man, float X, float Y, float W, float H, bool col)
{
	window = win;
	manager = man;

	position = sf::Vector2f(X, Y);
	velocity = sf::Vector2f(0, 0);
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	collides = col;
}
GameObject::GameObject(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float W, float H, bool col)
{
	window = win;
	manager = man;

	position = pos;
	velocity = sf::Vector2f(0, 0);
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	collides = col;
}
GameObject::GameObject(sf::RenderWindow* win, GameManager* man, float X, float Y, float velX, float velY, float W, float H, bool col)
{
	window = win;
	manager = man;

	position = sf::Vector2f(X, Y);
	velocity = sf::Vector2f(velX, velY);
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	collides = col;
}
GameObject::GameObject(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, sf::Vector2f vel, float W, float H, bool col)
{
	window = win;
	manager = man;

	position = pos;
	velocity = vel;
	anchor = sf::Vector2f(0, 0);

	width = W;
	height = H;
	collides = col;
}
GameObject::~GameObject()
{}

sf::Vector2f GameObject::GetPosition()
{	return position;	}
void GameObject::SetPosition(sf::Vector2f newPos)
{	position = newPos;	}
sf::Vector2f GameObject::GetVelocity()
{	return velocity;	}
void GameObject::SetVelocity(sf::Vector2f newVel)
{	velocity = newVel;	}
sf::Vector2f GameObject::GetAnchor()
{	return anchor;	}
void GameObject::SetAnchor(sf::Vector2f newAnc)
{	anchor = newAnc;	}

float GameObject::GetWidth()
{	return width;	}
float GameObject::getHeight()
{	return height;	}
bool GameObject::HasCollision()
{	return collides;	}
void GameObject::SetCollision(bool newCol)
{	collides = newCol;	}

sf::FloatRect GameObject::GetRect(GameObject* obj)
{
	float left = obj->position.x - obj->anchor.x;
	float top = obj->position.y - obj->anchor.y;
	
	return sf::FloatRect(left, top, obj->width, obj->height);
}
bool GameObject::ContainsPoint(sf::Vector2f point)
{	return GameObject::GetRect(this).contains(point);	}
bool GameObject::Collide(GameObject* obj)
{	return GameObject::GetRect(obj).intersects(GameObject::GetRect(this));	}
bool* GameObject::Collide(sf::Window* win, bool* hits)
{
	// Returns a boolian array listing the sides of the window that the object collided with

	hits[0] = (position.x - anchor.x <= 0);
	hits[1] = (position.x - anchor.x + width >= win->getSize().x);
	hits[2] = (position.y - anchor.y <= 0);
	hits[3] = (position.y - anchor.y + height >= win->getSize().y);

	return hits;
}

void GameObject::Update(float deltaTime)
{
	oldPosition = position;
	position += velocity * deltaTime;
}