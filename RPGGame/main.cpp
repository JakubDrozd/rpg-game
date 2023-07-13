#include "Player.h"
#include "Skeleton.h"
#include "Math.h"
#include <iostream>

using namespace sf;
using namespace std;


int main(){

	Player player;
	Skeleton skeleton;

	//-------------------------------------------- INIT ---------------------------------------------

	player.initialize();  
	skeleton.initialize();

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(1360, 768), "RPGGame", Style::Default, settings);

	window.setFramerateLimit(144);


	//-------------------------------------------- INIT ---------------------------------------------
	//-------------------------------------------- LOAD ---------------------------------------------
	player.load();
	skeleton.load();
	//-------------------------------------------- LOAD ---------------------------------------------


	Clock clock;

	//game loop (frame)
	while (window.isOpen())
	{

		//--------------------------------------- UPDATE ---------------------------------------------
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
			
		Time delta_time_raw = clock.restart();
		float delta_time = delta_time_raw.asMilliseconds();
		cout << delta_time << endl;

		skeleton.update(delta_time);
		player.update(skeleton, delta_time);


		//--------------------------------------- UPDATE ---------------------------------------------



		//---------------------------------------- DRAW ---------------------------------------------
		window.clear(Color::Black);

		skeleton.draw(window);
		player.draw(window);


		window.display();
		//---------------------------------------- DRAW ---------------------------------------------
	}

	return 0;
}