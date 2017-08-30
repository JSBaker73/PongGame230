#include "AppState.h"

AppState::AppState()
{}
AppState::AppState(sf::RenderWindow* win)
{
	window = win;
	closing = false;
}
AppState::~AppState()
{	GM.reset();	}

void AppState::Initialize()
{	GM->Initialize();	}
bool AppState::GetClosing()
{	return closing;	}