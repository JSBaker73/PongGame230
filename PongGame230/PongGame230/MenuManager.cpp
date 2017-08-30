#include "MenuManager.h"

MenuManager::MenuManager()
{}
MenuManager::MenuManager(sf::RenderWindow* win)
	: GameManager(win)
{}
MenuManager::~MenuManager()
{
	int a = 0;
}

void MenuManager::Initialize()
{
	start1 = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)/4,150.f,50.f,"P1 v P2");
	start2 = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)/2, 150.f, 50.f, "P1 v AI");
	exit = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)*3/4, 150.f, 50.f, "Exit Game");
	this->AddUIObject(start1);
	this->AddUIObject(start2);
	this->AddUIObject(exit);
}

UIButton* MenuManager::GetStart1()
{	return start1.get();	}
UIButton* MenuManager::GetStart2()
{	return start2.get();	}
UIButton* MenuManager::GetExit()
{	return exit.get();	}

void MenuManager::Update()
{

}