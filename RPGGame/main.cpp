#include "Player.h"
#include "Skeleton.h"

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
	window.setFramerateLimit(60);


	//-------------------------------------------- INIT ---------------------------------------------
	//-------------------------------------------- LOAD ---------------------------------------------
	player.load();
	skeleton.load();
	//-------------------------------------------- LOAD ---------------------------------------------




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
		
		skeleton.update();
		player.update(skeleton);
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