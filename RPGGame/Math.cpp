#include "Math.h"

using namespace std;

Vector2f Math::normalize_vector(Vector2f vector)
{
	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
	Vector2f normalized_vector;
	normalized_vector.x = vector.x / magnitude;
	normalized_vector.y = vector.y / magnitude;
	return normalized_vector;
}



bool Math::did_rect_collide(FloatRect rectangle1, FloatRect rectangle2)
{
	float rectangle1_right = rectangle1.left + rectangle1.width;
	float rectangle2_right = rectangle2.left + rectangle2.width;

	float rectangle1_bottom = rectangle1.top + rectangle1.height;
	float rectangle2_bottom = rectangle2.top + rectangle2.height;

	if (rectangle1_right > rectangle2.left &&
		rectangle2_right > rectangle1.left &&
		rectangle2_bottom > rectangle1.top &&
		rectangle1_bottom > rectangle2.top)
	{
		return true;
	}

	return false;
}
