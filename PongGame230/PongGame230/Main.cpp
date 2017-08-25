#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

#include <memory>
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

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	std::unique_ptr<AppState> currentState(new MenuState());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}

			AppState* next = currentState->UpdateState(event);

			if (next != NULL)
			{
				currentState.reset(next);
				currentState->Initialize();
			}
		}

		// UPdate Stuff
		currentState->Update();
		// Draw Stuff
		window.clear(sf::Color(50, 200, 50));
		currentState->Draw();
		window.display();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}