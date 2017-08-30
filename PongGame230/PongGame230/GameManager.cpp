#include "GameManager.h"
#include "GameObject.h"
#include "UIObject.h"

GameManager::GameManager()
{
	started = false;
	ended = false;
}
GameManager::GameManager(sf::RenderWindow* win)
{
	window = win;
	started = false;
	ended = false;
}
GameManager::~GameManager()
{
	GOList.clear();
	UIList.clear();
	int a = 0;
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
{	GOList.erase(GOList.begin() + index);	}
void GameManager::AddUIObject(std::shared_ptr<UIObject> obj)
{	UIList.push_back(obj);	}
void GameManager::RemoveUIObject(int index)
{	UIList.erase(UIList.begin() + index);	}

void GameManager::Update()
{
	float deltaTime = clock.restart().asSeconds();

	for (auto it = UIList.begin(); it != UIList.end(); ++it) {
		int index = std::distance(UIList.begin(), it);
		UIList.at(index)->Update(deltaTime);
		if (UIList.at(index)->GetToBeDeleted())
		{	it = UIList.erase(it);	}
		else
		{	++it;	}
	}
	for (auto it = GOList.begin(); it != GOList.end(); ) {
		int index = std::distance(GOList.begin(), it);
		GOList.at(index)->Update(deltaTime);
		if (GOList.at(index)->GetToBeDeleted())
		{	it = GOList.erase(it);	}
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
		{	collisions.push_back(obj);	}
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