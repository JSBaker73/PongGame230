#include "PongState.h"

#include "MenuState.h"
PongState::PongState()
{}
PongState::PongState(sf::RenderWindow* win, int mode)
	: AppState(win)
{
	GM = std::make_shared<PongManager>(win,this);
	currentMode = static_cast<GameMode>(mode);
}
PongState::~PongState()
{}

GameMode PongState::GetGameMode()
{	return currentMode;	}

AppState* PongState::UpdateState(sf::Event event)
{
	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
	{
		if (!GM->HasStarted())
		{	GM->Start();	}
		else if (dynamic_cast<PongManager*>(GM.get())->GetBallActive())
		{	dynamic_cast<PongManager*>(GM.get())->ShootBall();	}
		else if (GM->HasEnded())
		{	return new MenuState(window);	}
	}

	return NULL;
}
void PongState::Update()
{	GM->Update();	}
void PongState::Draw()
{	GM->Draw();	}