#include "Skeleton.h"
#include <iostream>

using namespace std;

void Skeleton::load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
	{
		int XIndex = 0;
		int YIndex = 2;

		cout << "+++Skeleton texture loaded+++" << endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(Vector2f(3, 3));
		sprite.setPosition(Vector2f(400, 400));
	}
	else
	{
		cout << "!!!Error loading Enemy texture!!!";
	}
}

void Skeleton::initialize()
{
}

void Skeleton::update()
{
	FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2, bounds.height / 2);

}

void Skeleton::draw(RenderWindow &window)
{
	window.draw(sprite);
}
