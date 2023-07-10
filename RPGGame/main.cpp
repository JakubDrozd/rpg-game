#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main(){

	//-------------------------------------------- INIT ---------------------------------------------

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(800, 600), "RPGGame", Style::Default, settings);


	//-------------------------------------------- INIT ---------------------------------------------

	//-------------------------------------------- LOAD ---------------------------------------------
	Texture playerTexture;
	Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		int XIndex = 0;
		int YIndex = 0;

		cout << "Player image loaded" << endl;
		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		playerSprite.scale(Vector2f(3, 3));
	}
	else
	{
		cout << "Error loading Player image";
	}


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

		float movement_speed = 1.0f;
		Vector2f curr_position = playerSprite.getPosition();
		
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			cout << "Moving right" << endl;
			playerSprite.setPosition(curr_position + Vector2f(movement_speed, 0));
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			playerSprite.setPosition(curr_position + Vector2f(-movement_speed, 0));

		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			cout << "Moving down" << endl;
			playerSprite.setPosition(curr_position + Vector2f(0, movement_speed));
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			cout << "Moving up" << endl;
			playerSprite.setPosition(curr_position + Vector2f(0, -movement_speed));
		}
		//--------------------------------------- UPDATE ---------------------------------------------



		//---------------------------------------- DRAW ---------------------------------------------
		window.clear(Color::Black);

		window.draw(playerSprite);

		window.display();
		//---------------------------------------- DRAW ---------------------------------------------
	}

	return 0;
}