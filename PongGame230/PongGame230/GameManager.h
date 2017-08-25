#pragma once

#include <algorithm>
#include <memory>
#include <vector>
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
//#include "GameObject.h"
//#include "UIObject.h"
class GameObject;
class UIObject;

class GameManager
{
protected:
	sf::RenderWindow* window;

	std::vector<std::shared_ptr<GameObject>> GOList;
	std::vector<std::shared_ptr<UIObject>> UIList;
	sf::Clock clock;

	bool isPlaying;
public:
	GameManager();
	GameManager(sf::RenderWindow* win);
	virtual ~GameManager();

	virtual void Initialize() = 0;
	virtual void Start();

	bool StillPlaying();

	void AddGameObject(std::shared_ptr<GameObject> obj);
	void RemoveGameObject(int index);
	void AddUIObject(std::shared_ptr<UIObject> obj);
	void RemoveUIObject(int index);

	virtual void Update();
	void Draw();

	std::vector<GameObject*> GetCollisions(GameObject* obj);
	UIObject* GetClicked(sf::Vector2i mousePos);
};

