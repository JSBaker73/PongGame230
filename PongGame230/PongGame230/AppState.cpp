#include "AppState.h"

AppState::AppState()
{}
AppState::AppState(sf::RenderWindow* win)
{	window = win;	}
AppState::~AppState()
{}

void AppState::Initialize()
{	GM->Initialize();	}