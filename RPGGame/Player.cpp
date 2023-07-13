#include "Player.h"
#include <iostream>
#include "Math.h"

using namespace std;

void Player::initialize()
{
	size = Vector2i(64, 64);

	boundingRectangle.setFillColor(Color::Transparent);
	boundingRectangle.setOutlineColor(Color::Red);
	boundingRectangle.setOutlineThickness(1);
}

void Player::load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		int XIndex = 0;
		int YIndex = 0;

		cout << "+++Player texture loaded+++" << endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(Vector2f(0, 0));
		sprite.scale(Vector2f(3, 3));
		boundingRectangle.setSize(Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		cout << "!!!Error loading Player texture!!!";
	}
}

void Player::update(Skeleton& skeleton, float delta_time)
{


	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		cout << "Moving right" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(1, 0) * speed *  delta_time);
		sprite.setTextureRect(IntRect(1 * size.x, 3 * size.y, size.x, size.y));
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		cout << "Moving left" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(-1, 0) * speed * delta_time);
		sprite.setTextureRect(IntRect(1 * size.x, 1 * size.y, size.x, size.y));
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		cout << "Moving down" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(0, 1) * speed * delta_time);
		sprite.setTextureRect(IntRect(0 * size.x, 2 * size.y, size.x, size.y));
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		cout << "Moving up" << endl;
		Vector2f curr_position = sprite.getPosition();
		sprite.setPosition(curr_position + Vector2f(0, -1) * speed * delta_time);
		sprite.setTextureRect(IntRect(0 * size.x, 0 * size.y, size.x, size.y));
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
		bullets[i].setPosition(bullets[i].getPosition() + bullet_direction * bullet_speed * delta_time);
	}

	boundingRectangle.setPosition(sprite.getPosition());

	if (Math::did_rect_collide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
	{
		cout << "***Collision detected***" << endl;
	}
}

void Player::draw(RenderWindow &window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}

	window.draw(boundingRectangle);
}
