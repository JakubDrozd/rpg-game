#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Skeleton
{
private:
	Texture texture;

public:
	Sprite sprite;

public:
	void load();
	void initialize();
	void update();
	void draw(RenderWindow &window);
};

