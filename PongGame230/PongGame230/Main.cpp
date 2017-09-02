#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include <iostream>
#include <memory>
#include <ctime>
#include "MenuState.h"


#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif


int main()
{
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);

	// Seed Random
	srand((unsigned)time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 600), "JS Baker's Pong");

	std::unique_ptr<AppState> currentState(new MenuState(&window));
	currentState->Initialize();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			AppState* next = currentState->UpdateState(event);

			if (next != NULL)
			{
				currentState.reset(next);
				currentState->Initialize();
			}

			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) ||
					currentState->GetClosing()))
			{
				window.close();
				break;
			}	
		}
		
		// UPdate Stuff
		currentState->Update();
		// Draw Stuff
		window.clear(sf::Color(50, 50, 200));
		currentState->Draw();
		window.display();
	}
	currentState.reset();
	_CrtDumpMemoryLeaks();
	return 0;
}