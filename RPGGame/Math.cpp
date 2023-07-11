#include "Math.h"

Vector2f Math::normalize_vector(Vector2f vector)
{
	float magnitude = sqrt(vector.x * vector.x + vector.y * vector.y);
	Vector2f normalized_vector;
	normalized_vector.x = vector.x / magnitude;
	normalized_vector.y = vector.y / magnitude;
	return normalized_vector;
}
