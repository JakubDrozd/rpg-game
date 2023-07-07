#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main(){

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(800, 600), "RPGGame", Style::Default, settings);

	CircleShape triangle(70.0f, 3);
	triangle.setPosition(365, 265);
	triangle.setFillColor(Color::Magenta);

	cout << triangle.getOrigin().x << " " << triangle.getOrigin().y << endl;

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
		//--------------------------------------- UPDATE ---------------------------------------------



		//---------------------------------------- DRAW ---------------------------------------------
		window.clear(Color::Black);


		window.draw(triangle);

		window.display();
		//---------------------------------------- DRAW ---------------------------------------------
	}

	return 0;
}