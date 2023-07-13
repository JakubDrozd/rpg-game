#pragma once
#include "Skeleton.h"

using namespace std;

class Player
{
private:
	Texture texture;

	vector<RectangleShape> bullets;

	RectangleShape boundingRectangle;

	Vector2i size;

	float bullet_speed = 0.5f;

	float speed = 1.3f;

public:
	Sprite sprite;

public:
	void initialize(); 
	void load();
	void update(Skeleton &skeleton, float delta_time); 
	void draw(RenderWindow &window); 

};

