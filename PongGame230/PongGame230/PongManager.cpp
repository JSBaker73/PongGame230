#include "PongManager.h"

#include "PongState.h"
PongManager::PongManager()
{
	team1Score = 0;
	team2Score = 0;
}
PongManager::PongManager(sf::RenderWindow* win, PongState* pongState)
	: GameManager(win)
{
	PS = pongState;
	team1Score = 0;
	team2Score = 0;
}
PongManager::~PongManager()
{
	paddles.clear();
	winMessages.clear();
}

Ball* PongManager::GetBall()
{	return ball.get();	}
bool PongManager::GetBallActive()
{	return ball->IsActive();	}

void PongManager::Initialize()
{
	ball = std::make_shared<Ball>(window, this, (static_cast<sf::Vector2f>(window->getSize()) / 2.f), 10.f);
	this->AddGameObject(ball);
	
	switch (PS->GetGameMode())
	{
	case GameMode::PVP:
		paddles.push_back(std::make_shared<PlayerPaddle>(window, this, sf::Vector2f(25.f, (float)(window->getSize().y) / 2), 25.f, 100.f, 0, true));
		paddles.push_back(std::make_shared<PlayerPaddle>(window, this, (float)(window->getSize().x) - 25.f, (float)(window->getSize().y) / 2, 25.f, 100.f, 1, true));
		
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)/4,(float)(window->getSize().y)/2, 28, "Player 1"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)/4, instructions.back()->GetPosition().y+instructions.back()->GetHeight()*1.5f, 28, "WASD"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)*3/4, (float)(window->getSize().y)/2, 28, "Player 2"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)*3/4, instructions.back()->GetPosition().y + instructions.back()->GetHeight()*1.5f, 28, "Arrow Keys"));
		break;
	case GameMode::PVAI:
		paddles.push_back(std::make_shared<PlayerPaddle>(window, this, sf::Vector2f(25.f, (float)(window->getSize().y) / 2), 25.f, 100.f, 0, true));
		paddles.push_back(std::make_shared<AIPaddle>(window, this, (float)(window->getSize().x) - 25.f, (float)(window->getSize().y) / 2, 25.f, 100.f, 1, true));
		
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)/4, (float)(window->getSize().y)/2, 28, "Player 1"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)/4, instructions.back()->GetPosition().y + instructions.back()->GetHeight()*1.5f, 28, "WASD"));
		break;
	case GameMode::TVT:
		paddles.push_back(std::make_shared<PlayerPaddle>(window, this, sf::Vector2f(65.f, (float)(window->getSize().y) / 2), 25.f, 100.f, 0, true));
		paddles.push_back(std::make_shared<PlayerPaddle>(window, this, (float)(window->getSize().x) - 65.f, (float)(window->getSize().y) / 2, 25.f, 100.f, 1, true));
		paddles.push_back(std::make_shared<AIPaddle>(window, this, 25.f, (float)(window->getSize().y) / 2, 25.f, 100.f, 1, true));
		paddles.push_back(std::make_shared<AIPaddle>(window, this, (float)(window->getSize().x) - 25.f, (float)(window->getSize().y) / 2, 25.f, 100.f, 1, true));
		
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)/4, (float)(window->getSize().y)/2, 28, "Player 1"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)/4, instructions.back()->GetPosition().y + instructions.back()->GetHeight()*1.5f, 28, "WASD"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)*3/4, (float)(window->getSize().y)/2, 28, "Player 2"));
		instructions.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x)*3/4, instructions.back()->GetPosition().y + instructions.back()->GetHeight()*1.5f, 28, "Arrow Keys"));
		break;
	default:
		break;
	}
	for (auto it = paddles.begin(); it != paddles.end(); ++it)
	{
		int index = std::distance(paddles.begin(), it);
		this->AddGameObject(paddles.at(index));
	}
	for (auto it = instructions.begin(); it != instructions.end(); ++it)
	{
		int index = std::distance(instructions.begin(), it);
		this->AddUIObject(instructions.at(index));
	}

	team1Label = std::make_shared<UILabel>(window, (float)(window->getSize().x) / 4, (float)(window->getSize().y) / 5, 40, "Team 1");
	team1ScoreLabel = std::make_shared<UILabel>(window, team1Label->GetPosition().x, team1Label->GetPosition().y + team1Label->GetHeight() * 1.75f, 50, std::to_string(team1Score));
	team2Label = std::make_shared<UILabel>(window, (float)(window->getSize().x) * 3 / 4, (float)(window->getSize().y) / 5, 40, "Team 2");
	team2ScoreLabel = std::make_shared<UILabel>(window, team2Label->GetPosition().x, team2Label->GetPosition().y + team1Label->GetHeight() * 1.75f, 50, std::to_string(team2Score));
	startText = std::make_shared<UILabel>(window, ball->GetPosition().x, (float)(window->getSize().y)*3/4, 28, "Press SPACE to start");
	exitText = std::make_shared<UILabel>(window, ball->GetPosition().x, startText->GetPosition().y + startText->GetHeight()*1.5f, 28, "Press BACKSPACE to exit to the menu");
	this->AddUIObject(team1Label);
	this->AddUIObject(team1ScoreLabel);
	this->AddUIObject(team2Label);
	this->AddUIObject(team2ScoreLabel);
	this->AddUIObject(startText);
	this->AddUIObject(exitText);
}
void PongManager::Start()
{
	started = true;
	this->team1Label->SetVisible(false);
	this->team1ScoreLabel->SetVisible(false);
	this->team2Label->SetVisible(false);
	this->team2ScoreLabel->SetVisible(false);
	this->startText->SetVisible(false);
	this->exitText->SetVisible(false);

	for (auto it = instructions.begin(); it != instructions.end(); ++it)
	{
		int index = std::distance(instructions.begin(), it);
		instructions.at(index)->SetVisible(false);
	}

	switch (PS->GetGameMode())
	{
	case GameMode::PVP:
		break;
	case GameMode::PVAI:
		dynamic_cast<AIPaddle*>(paddles.at(1).get())->Start();
		break;
	case GameMode::TVT:
		dynamic_cast<AIPaddle*>(paddles.at(2).get())->Start();
		dynamic_cast<AIPaddle*>(paddles.at(3).get())->Start();
		break;
	default:
		break;
	}

	this->ShootBall();
}
void PongManager::Stop()
{
	started = false;
	team1Label->SetVisible(true);
	team1ScoreLabel->SetVisible(true);
	team2Label->SetVisible(true);
	team2ScoreLabel->SetVisible(true);
	startText->SetVisible(true);
	exitText->SetVisible(true);

	for (auto it = instructions.begin(); it != instructions.end(); ++it)
	{
		int index = std::distance(instructions.begin(), it);
		instructions.at(index)->SetVisible(true);
	}

	switch (PS->GetGameMode())
	{
	case GameMode::PVP:
		break;
	case GameMode::PVAI:
		dynamic_cast<AIPaddle*>(paddles.at(1).get())->Stop();
		break;
	case GameMode::TVT:
		dynamic_cast<AIPaddle*>(paddles.at(2).get())->Stop();
		dynamic_cast<AIPaddle*>(paddles.at(3).get())->Stop();
		break;
	default:
		break;
	}

	bool team = (ball->GetPosition().x > (float)window->getSize().x / 2);

	for (auto it = GOList.begin(); it != GOList.end(); ++it)
	{
		int index = std::distance(GOList.begin(), it);
		if (GOList.at(index) == ball)
		{
			this->RemoveGameObject(index);
			break;
		}
	}

	this->Score(team);

	if (!ended)
	{
		ball.reset();
		ball = std::make_shared<Ball>(window, this, (static_cast<sf::Vector2f>(window->getSize()) / 2.f), 10.f);
		this->AddGameObject(ball);

		startText->SetVisible(true);
	}
	else
	{
		winMessages.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x) / 2, (float)(window->getSize().y) * 2 / 5, 28, (team1Score == 5 ? "Team 1 Wins!" : "Team 2 Wins!")));
		winMessages.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x) / 2, winMessages.back()->GetPosition().y + winMessages.back()->GetHeight() * 1.75f, 28, "Press SPACE to play again"));
		winMessages.push_back(std::make_shared<UILabel>(window, (float)(window->getSize().x) / 2, winMessages.back()->GetPosition().y + winMessages.back()->GetHeight() * 1.5f, 28, "Press BACKSPACE to exit to the menu"));
		
		for (auto it = winMessages.begin(); it != winMessages.end(); ++it)
		{
			int index = std::distance(winMessages.begin(), it);
			this->AddUIObject(winMessages.at(index));
		}
	}
}
void PongManager::End()
{	ended = true;	}
void PongManager::ShootBall()
{
	float angle = (float)(std::rand() % 180);
	if (angle < 90)
	{	angle -= 45;	}
	else
	{	angle += 45;	}

	ball->Start(angle);
}

void PongManager::Score(bool team1)
{
	if (team1)
	{
		team1Score += 1;
		team1ScoreLabel->SetText(std::to_string(team1Score));
	}
	else
	{
		team2Score += 1;
		team2ScoreLabel->SetText(std::to_string(team2Score));
	}

	if (this->CheckWin())
	{	this->End();	}
}
bool PongManager::CheckWin()
{
	if (team1Score >= 5 || team2Score >= 5)
	{	return true;	}
	else
	{	return false;	}
}