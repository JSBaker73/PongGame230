#include "GameManager.h"
#include "GameObject.h"
#include "UIObject.h"

GameManager::GameManager()
{
	started = false;
	ended = false;
	GODeleted = false;
	UIDeleted = false;
}
GameManager::GameManager(sf::RenderWindow* win)
{
	window = win;
	started = false;
	ended = false;
	GODeleted = false;
	UIDeleted = false;
}
GameManager::~GameManager()
{
	GOList.clear();
	UIList.clear();
}

void GameManager::Start()
{
	clock.restart();
	started = true;
}
void GameManager::End()
{	ended = true;	}

bool GameManager::HasStarted()
{	return started;	}
bool GameManager::HasEnded()
{	return ended;	}

void GameManager::AddGameObject(std::shared_ptr<GameObject> obj)
{	GOList.push_back(obj);	}
void GameManager::RemoveGameObject(int index)
{
	GOList.erase(GOList.begin() + index);
	GODeleted = true;
}
void GameManager::AddUIObject(std::shared_ptr<UIObject> obj)
{	UIList.push_back(obj);	}
void GameManager::RemoveUIObject(int index)
{
	UIList.erase(UIList.begin() + index);
	UIDeleted = true;
}

void GameManager::Update()
{
	float deltaTime = clock.restart().asSeconds();

	for (auto it = UIList.begin(); it != UIList.end(); ) {
		int index = std::distance(UIList.begin(), it);
		UIList.at(index)->Update(deltaTime);
		if (UIDeleted)
		{
			it = UIList.begin() + index;
			UIDeleted = false;
		}
		else
		{	++it;	}
	}
	for (auto it = GOList.begin(); it != GOList.end(); ) {
		int index = std::distance(GOList.begin(), it);
		GOList.at(index)->Update(deltaTime);
		if (GODeleted)
		{
			it = GOList.begin() + index;
			GODeleted = false;
		}
		else
		{	++it;	}
	}
}
void GameManager::Draw()
{
	for (auto it = GOList.begin(); it != GOList.end(); ++it) {
		int index = std::distance(GOList.begin(), it);
		GOList.at(index)->Draw();
	}
	for (auto it = UIList.begin(); it != UIList.end(); ++it) {
		int index = std::distance(UIList.begin(), it);
		UIList.at(index)->Draw();
	}
}

std::vector<GameObject*> GameManager::GetCollisions(GameObject* obj)
{
	std::vector<GameObject*> collisions;

	for (auto it = GOList.begin(); it != GOList.end(); ++it) {
		int index = std::distance(GOList.begin(), it);
 		if (!GOList.at(index)->HasCollision() || GOList.at(index).get() == obj)
		{	continue;	}
		if (GOList.at(index)->Collide(obj))
		{	collisions.push_back(GOList.at(index).get());	}
	}

	return collisions;
}
UIObject* GameManager::GetClicked(sf::Vector2i mousePos)
{
	UIObject* clicked;

	for (auto it = UIList.begin(); it != UIList.end(); ++it) {
		int index = std::distance(UIList.begin(), it);
		if (!UIList.at(index)->GetClickable())
		{	continue;	}
		if (UIList.at(index)->ContainsPoint(sf::Vector2f(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))))
		{
			clicked = UIList.at(index).get();
			return clicked;
		}
	}

	return NULL;
}