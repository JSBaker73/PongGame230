#pragma once

#include "GameManager.h"
#include "UIButton.h"
#include "UILabel.h"
class MenuManager : public GameManager
{
protected:
	std::shared_ptr<UILabel> title;
	std::shared_ptr<UIButton> start1;
	std::shared_ptr<UIButton> start2;
	std::shared_ptr<UIButton> start3;
	std::shared_ptr<UIButton> exit;
public:
	MenuManager();
	MenuManager(sf::RenderWindow* win);
	~MenuManager();

	virtual void Initialize();
	virtual void Stop();

	UIButton* GetStart1();
	UIButton* GetStart2();
	UIButton* GetStart3();
	UIButton* GetExit();

	virtual void Update();
};

