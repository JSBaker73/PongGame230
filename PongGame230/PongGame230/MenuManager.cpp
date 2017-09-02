#include "MenuManager.h"

MenuManager::MenuManager()
{}
MenuManager::MenuManager(sf::RenderWindow* win)
	: GameManager(win)
{}
MenuManager::~MenuManager()
{}

void MenuManager::Initialize()
{
	title = std::make_shared<UILabel>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)*3/14, 100, "Pong");
	start1 = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)*3/7, 325.f,50.f,"P1 v P2");
	start2 = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)*4/7, 325.f, 50.f, "P1 v AI");
	start3 = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)*5/7, 325.f, 50.f, "P1 + AI v P2 + AI");
	exit = std::make_shared<UIButton>(window, (float)(window->getSize().x)/2, (float)(window->getSize().y)*6/7, 325.f, 50.f, "Exit Game");
	start1->SetAnchor(sf::Vector2f(start1->GetWidth() / 2, start1->GetHeight() / 2));
	start2->SetAnchor(sf::Vector2f(start2->GetWidth() / 2, start2->GetHeight() / 2));
	start3->SetAnchor(sf::Vector2f(start3->GetWidth() / 2, start3->GetHeight() / 2));
	exit->SetAnchor(sf::Vector2f(exit->GetWidth() / 2, exit->GetHeight() / 2));
	this->AddUIObject(title);
	this->AddUIObject(start1);
	this->AddUIObject(start2);
	this->AddUIObject(start3);
	this->AddUIObject(exit);
}
void MenuManager::Stop()
{}

UIButton* MenuManager::GetStart1()
{	return start1.get();	}
UIButton* MenuManager::GetStart2()
{	return start2.get();	}
UIButton* MenuManager::GetStart3()
{	return start3.get();	}
UIButton* MenuManager::GetExit()
{	return exit.get();	}

void MenuManager::Update()
{}