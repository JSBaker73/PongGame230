#pragma once

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

class GameManager;

class GameObject
{
protected:
	sf::RenderWindow* window;
	GameManager* manager;

	sf::Vector2f oldPosition;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f anchor;

	float width;
	float height;
	bool collides;
public:
	GameObject();
	GameObject(sf::RenderWindow* win, GameManager* man, float X, float Y, float W, float H, bool col);
	GameObject(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, float W, float H, bool col);
	GameObject(sf::RenderWindow* win, GameManager* man, float X, float Y, float velX, float velY, float W, float H, bool col);
	GameObject(sf::RenderWindow* win, GameManager* man, sf::Vector2f pos, sf::Vector2f vel, float W, float H, bool col);
	virtual ~GameObject();

	sf::Vector2f GetPosition();
	virtual void SetPosition(sf::Vector2f newPos);
	sf::Vector2f GetVelocity();
	virtual void SetVelocity(sf::Vector2f newVel);
	sf::Vector2f GetAnchor();
	virtual void SetAnchor(sf::Vector2f newAnc);

	float GetWidth();
	float getHeight();
	bool HasCollision();
	void SetCollision(bool newCol);

	static sf::FloatRect GetRect(GameObject* obj);
	virtual bool ContainsPoint(sf::Vector2f point);
	virtual bool Collide(GameObject* other);
	virtual bool* Collide(sf::Window* win, bool* hits);
	virtual void Hit(GameObject* other, sf::FloatRect* rect) = 0;

	virtual void Update(float deltaTime);
	virtual void Draw() = 0;
};

