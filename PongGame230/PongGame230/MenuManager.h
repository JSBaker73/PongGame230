#pragma once

#include "GameManager.h"
#include "UIButton.h"
class MenuManager : virtual public GameManager
{
protected:
	std::shared_ptr<UIButton> start1;
	std::shared_ptr<UIButton> start2;
	std::shared_ptr<UIButton> exit;
public:
	MenuManager();
	MenuManager(sf::RenderWindow* win);
	~MenuManager();

	virtual void Initialize();

	UIButton* GetStart1();
	UIButton* GetStart2();
	UIButton* GetExit();

	virtual void Update();
};

