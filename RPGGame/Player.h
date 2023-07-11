#pragma once
#include "Skeleton.h"

using namespace std;

class Player
{
private:
	Texture texture;

	vector<RectangleShape> bullets;
	float bullet_speed = 15.0f;

public:
	Sprite sprite;

public:
	void initialize(); 
	void load();
	void update(Skeleton &skeleton); 
	void draw(RenderWindow &window); 

};

