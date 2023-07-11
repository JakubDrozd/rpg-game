#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

using namespace sf;
using namespace std;

Vector2f normalize_vector(Vector2f vector) {
	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
	Vector2f normalized_vector;
	normalized_vector.x = vector.x / magnitude;
	normalized_vector.y = vector.y / magnitude;
	return normalized_vector;
}

int main(){

	//-------------------------------------------- INIT ---------------------------------------------

	ContextSettings settings;
	settings.antialiasingLevel = 8;

	RenderWindow window(VideoMode(1280, 720), "RPGGame", Style::Default, settings);
	window.setFramerateLimit(60);


	//-------------------------------------------- INIT ---------------------------------------------


	//-------------------------------------------- LOAD ---------------------------------------------
	Texture playerTexture;
	Sprite playerSprite;

	Texture skeletonTexture;
	Sprite skeletonSprite;

	float movement_speed = 8.0f;

	//------------------------------------------ SKELETON ---------------------------------------------
	if (skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		int XIndex = 0;
		int YIndex = 2;

		cout << "Skeleton texture loaded" << endl;
		skeletonSprite.setTexture(skeletonTexture);
		skeletonSprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		skeletonSprite.scale(Vector2f(3, 3));
		skeletonSprite.setPosition(Vector2f(400, 400));
	}
	else
	{
		cout << "Error loading Enemy texture";
	}
	//------------------------------------------ SKELETON ---------------------------------------------

	//------------------------------------------- PLAYER ---------------------------------------------
	if (playerTexture.loadFromFile("Assets/Player/Textures/characters.png"))
	{
		int XIndex = 0;
		int YIndex = 1;

		cout << "Player texture loaded" << endl;
		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(IntRect(XIndex * 32, YIndex * 32, 32, 32));
		playerSprite.scale(Vector2f(5, 5));
		playerSprite.setPosition(Vector2f(1000, 400));
	}
	else
	{
		cout << "Error loading Player texture";
	}
	//------------------------------------------- PLAYER ---------------------------------------------

	vector<RectangleShape> bullets;


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
		
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			cout << "Moving right" << endl;
			Vector2f curr_position = playerSprite.getPosition();
			playerSprite.setPosition(curr_position + Vector2f(movement_speed, 0));
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			cout << "Moving left" << endl;
			Vector2f curr_position = playerSprite.getPosition();
			playerSprite.setPosition(curr_position + Vector2f(-movement_speed, 0));

		}

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			cout << "Moving down" << endl;
			Vector2f curr_position = playerSprite.getPosition();
			playerSprite.setPosition(curr_position + Vector2f(0, movement_speed));
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			cout << "Moving up" << endl;
			Vector2f curr_position = playerSprite.getPosition();
			playerSprite.setPosition(curr_position + Vector2f(0, -movement_speed));
		}

		if (Mouse::isButtonPressed(Mouse::Button::Left))
		{
			bullets.push_back(RectangleShape(Vector2f(25, 25)));

			int i = bullets.size() - 1;

			bullets[i].setPosition(playerSprite.getPosition());	
		}

		float bullet_speed = 15.0f;

		for (int i = 0; i < bullets.size(); i++)
		{
			Vector2f bullet_direction;
			bullet_direction = skeletonSprite.getPosition() - bullets[i].getPosition();
			bullet_direction = normalize_vector(bullet_direction);
			bullets[i].setPosition(bullets[i].getPosition() + bullet_direction * bullet_speed);
		}

		//--------------------------------------- UPDATE ---------------------------------------------



		//---------------------------------------- DRAW ---------------------------------------------
		window.clear(Color::Black);

		window.draw(skeletonSprite);
		window.draw(playerSprite);
		for (int i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}


		window.display();
		//---------------------------------------- DRAW ---------------------------------------------
	}

	return 0;
}