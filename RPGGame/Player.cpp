#include "Player.h"
#include <iostream>
#include "Math.h"

using namespace std;

void Player::initialize()
{
}

void Player::load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		int XIndex = 0;
		int YIndex = 0;

		cout << "+++Player texture loaded+++" << endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(Vector2f(3, 3));
		sprite.setPosition(Vector2f(1000, 400));
	}
	else
	{
		cout << "!!!Error loading Player texture!!!";
	}
}

void Player::update(Skeleton& skeleton)
{

	FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);

	float movement_speed = 8.0f;

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		cout << "Moving right" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(6.0f, 0));
		sprite.setTextureRect(IntRect(1 * 64, 3 * 64, 64, 64));
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		cout << "Moving left" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(-movement_speed, 0));
		sprite.setTextureRect(IntRect(1 * 64, 1 * 64, 64, 64));
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		cout << "Moving down" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(0, movement_speed));
		sprite.setTextureRect(IntRect(0 * 64, 2 * 64, 64, 64));
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		cout << "Moving up" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(0, -movement_speed));
		sprite.setTextureRect(IntRect(0 * 64, 0 * 64, 64, 64));
	}



	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		bullets.push_back(RectangleShape(Vector2f(25, 25)));

		int i = bullets.size() - 1;

		bullets[i].setPosition(sprite.getPosition());
		bullets[i].setFillColor(Color::White);
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		Vector2f bullet_direction;
		bullet_direction = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bullet_direction = Math::normalize_vector(bullet_direction);
		bullets[i].setPosition(bullets[i].getPosition() + bullet_direction * bullet_speed);
	}
}

void Player::draw(RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}
