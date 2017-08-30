#pragma once

#include <memory>
#include <SFML\Window\Event.hpp>
#include "GameManager.h"
class AppState
{
protected:
	std::shared_ptr<GameManager> GM;
	sf::RenderWindow* window;

	bool closing;
public:
	AppState();
	AppState(sf::RenderWindow* win);
	virtual ~AppState();

	void Initialize();

	bool GetClosing();

	virtual AppState* UpdateState(sf::Event event) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

