#include "MenuState.h"

MenuState::MenuState()
{}
MenuState::MenuState(sf::RenderWindow* win)
	: AppState(win)
{	GM = std::make_shared<MenuManager>();	}
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
			{

			}
			else if (uiObj == dynamic_cast<MenuManager*>(GM.get())->GetStart2())
			{

			}
			else if (uiObj == dynamic_cast<MenuManager*>(GM.get())->GetExit())
			{

			}
		}
	}

	return NULL;
}

void MenuState::Update()
{	GM->Update();	}
void MenuState::Draw()
{	GM->Draw();	}