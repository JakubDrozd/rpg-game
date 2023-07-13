#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Skeleton
{
private:
	Texture texture;
	RectangleShape boundingRectangle;

	Vector2i size;

public:
	Sprite sprite;

public:
	void load();
	void initialize();
	void update(float delta_time);
	void draw(RenderWindow &window);
};

