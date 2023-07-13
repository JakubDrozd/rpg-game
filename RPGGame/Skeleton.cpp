#include "Skeleton.h"
#include <iostream>

using namespace std;

void Skeleton::initialize()
{
	size = Vector2i(64, 64);

	boundingRectangle.setFillColor(Color::Transparent);
	boundingRectangle.setOutlineColor(Color::Cyan);
	boundingRectangle.setOutlineThickness(1);

}

void Skeleton::load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		int XIndex = 0;
		int YIndex = 2;

		cout << "+++Skeleton texture loaded+++" << endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
		sprite.setPosition(Vector2f(400, 400));
		sprite.scale(Vector2f(3, 3));
		boundingRectangle.setSize(Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		cout << "!!!Error loading Enemy texture!!!";
	}
}

void Skeleton::update(float delta_time)
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::draw(RenderWindow &window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}
