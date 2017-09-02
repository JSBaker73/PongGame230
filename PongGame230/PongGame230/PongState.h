#pragma once

#include "AppState.h"
#include "PongManager.h"

class MenuState;
enum class GameMode
{
	PVP,
	PVAI,
	TVT
};

class PongState : public AppState
{
public:
	PongState();
	PongState(sf::RenderWindow* win, int mode);
	PongState(sf::RenderWindow* win, GameMode mode);
	~PongState();

	GameMode GetGameMode();

	virtual AppState* UpdateState(sf::Event event);
	virtual void Update();
	virtual void Draw();
protected:
	GameMode currentMode;
};

