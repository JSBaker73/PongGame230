#include "UIButton.h"

UIButton::UIButton()
{
	clickable = true;

	button.setSize(sf::Vector2f(0, 0));
	button.setPosition(sf::Vector2f(0, 0));
	button.setFillColor(sf::Color::White);

	label.setString("");
	label.setFillColor(sf::Color::Black);
	label.setPosition(0, 0);
}
UIButton::UIButton(sf::RenderWindow* win, float X, float Y, float W, float H, std::string text)
	: UIObject(win,X,Y,W,H)
{
	clickable = true;

	button.setSize(sf::Vector2f(W, H));
	button.setPosition(sf::Vector2f(X, Y));
	button.setFillColor(sf::Color::White);

	font.loadFromFile("Resources/sansation.ttf");

	label.setString(text);
	label.setFont(font);
	label.setStyle(sf::Text::Regular);
	label.setCharacterSize(40);
	label.setFillColor(sf::Color::Black);
	label.setPosition(sf::Vector2f(X+W/2, Y+H/4));
	label.setOrigin(label.getLocalBounds().width/2,label.getLocalBounds().height/2);
}
UIButton::UIButton(sf::RenderWindow* win, sf::Vector2f pos, float W, float H, std::string text)
	: UIObject(win,pos,W,H)
{
	clickable = true;

	button.setSize(sf::Vector2f(W, H));
	button.setPosition(pos);
	button.setFillColor(sf::Color::White);

	font.loadFromFile("Resources/sansation.ttf");

	label.setString(text);
	label.setFont(font);
	label.setStyle(sf::Text::Regular);
	label.setCharacterSize(40);
	label.setFillColor(sf::Color::Black);
	label.setPosition(pos);
}
UIButton::~UIButton()
{}

void UIButton::SetPosition(sf::Vector2f newPos)
{
	UIObject::SetPosition(newPos);
	button.setPosition(newPos);
	label.setPosition(newPos);
}
void UIButton::SetAnchor(sf::Vector2f newAnc)
{
	sf::Vector2f oldAnch = button.getOrigin();
	UIObject::SetAnchor(newAnc);
	button.setOrigin(newAnc);
	label.setPosition(label.getPosition() + (oldAnch - newAnc));
}

void UIButton::Update(float deltaTime)
{}
void UIButton::Draw()
{
	window->draw(button);
	window->draw(label);
}