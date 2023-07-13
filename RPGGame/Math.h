#pragma once
#include <SFMl/Graphics.hpp>
using namespace sf;

class Math
{
public:
	static Vector2f normalize_vector(Vector2f vector);
	static bool did_rect_collide(FloatRect rect1, FloatRect rect2);
};

