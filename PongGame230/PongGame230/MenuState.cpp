#include "MenuState.h"

#include "PongState.h"
MenuState::MenuState()
{}
MenuState::MenuState(sf::RenderWindow* win)
	: AppState(win)
{	GM = std::make_shared<MenuManager>(win);	}
MenuState::~MenuState()
{}

AppState* MenuState::UpdateState(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		UIObject* uiObj = GM->GetClicked(mousePos);

		if (uiObj != NULL)
		{
			if (uiObj == dynamic_cast<MenuManager*>(GM.get())->GetStart1())
			{	return new PongState(window, 0);	}
			else if (uiObj == dynamic_cast<MenuManager*>(GM.get())->GetStart2())
			{	return new PongState(window, 1);	}
			else if (uiObj == dynamic_cast<MenuManager*>(GM.get())->GetStart3())
			{	return new PongState(window, 2);	}
			else if (uiObj == dynamic_cast<MenuManager*>(GM.get())->GetExit())
			{
				window->close();
				closing = true;
			}
		}
	}

	return NULL;
}

void MenuState::Update()
{}
void MenuState::Draw()
{	GM->Draw();	}