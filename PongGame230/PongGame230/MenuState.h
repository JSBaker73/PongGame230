#pragma once

#include "AppState.h"
#include "MenuManager.h"

class PongState;

class MenuState : public AppState
{
public:
	MenuState();
	MenuState(sf::RenderWindow* win);
	~MenuState();

	virtual AppState* UpdateState(sf::Event event);
	virtual void Update();
	virtual void Draw();
};

