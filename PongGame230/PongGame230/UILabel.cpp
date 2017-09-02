#include "UILabel.h"

UILabel::UILabel()
{
	label.setString("");
	label.setFillColor(sf::Color::White);
	label.setOutlineColor(sf::Color::Black);
	label.setPosition(0, 0);
	label.setOrigin(sf::Vector2f(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2));
}
UILabel::UILabel(sf::RenderWindow* win, float X, float Y, int size, std::string text)
	: UIObject(win, X, Y, 0.f, 0.f)
{
	font.loadFromFile("Resources/sansation.ttf");

	label.setString(text);
	label.setFont(font);
	label.setStyle(sf::Text::Regular);
	label.setCharacterSize(size);
	label.setFillColor(sf::Color::White);
	label.setOutlineColor(sf::Color::Black);
	label.setOutlineThickness(2.f);
	label.setPosition(sf::Vector2f(X, Y));
	label.setOrigin(sf::Vector2f(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2));

	anchor = label.getOrigin();

	width = label.getLocalBounds().width;
	height = label.getLocalBounds().height;
}
UILabel::UILabel(sf::RenderWindow* win, sf::Vector2f pos, int size, std::string text)
	: UIObject(win, pos, 0.f, 0.f)
{
	font.loadFromFile("Resources/sansation.ttf");

	label.setString(text);
	label.setFont(font);
	label.setStyle(sf::Text::Regular);
	label.setCharacterSize(size);
	label.setFillColor(sf::Color::White);
	label.setOutlineColor(sf::Color::Black);
	label.setOutlineThickness(2.f);
	label.setPosition(pos);
	label.setOrigin(sf::Vector2f(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2));

	anchor = label.getOrigin();

	width = label.getLocalBounds().width;
	height = label.getLocalBounds().height;
}
UILabel::~UILabel()
{}

int UILabel::GetSize()
{	return label.getCharacterSize();	}
void UILabel::SetSize(int size)
{
	label.setCharacterSize(size);
	label.setOrigin(sf::Vector2f(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2));

	anchor = label.getOrigin();

	width = label.getLocalBounds().width;
	height = label.getLocalBounds().height;
}
std::string UILabel::GetText()
{	return label.getString();	}
void UILabel::SetText(std::string text)
{
	label.setString(text);
	label.setOrigin(sf::Vector2f(label.getLocalBounds().width / 2, label.getLocalBounds().height / 2));

	anchor = label.getOrigin();

	width = label.getLocalBounds().width;
	height = label.getLocalBounds().height;
}

void UILabel::Update(float deltaTime)
{}
void UILabel::Draw()
{
	if (visible)
	{	window->draw(label);	}
}