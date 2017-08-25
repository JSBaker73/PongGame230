#pragma once

#include <memory>
#include <SFML\Window\Event.hpp>
#include "GameManager.h"
class AppState
{
protected:
	std::shared_ptr<GameManager> GM;
	sf::RenderWindow* window;
public:
	AppState();
	AppState(sf::RenderWindow* win);
	~AppState();

	void Initialize();

	virtual AppState* UpdateState(sf::Event event) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

