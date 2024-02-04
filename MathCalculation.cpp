#include "MathCalculation.h"

Vector2 LengthDis(const Vector2& endVec, const Vector2& startVec)
{
	Vector2 result{};
	result.x = endVec.x - startVec.x;
	result.y = endVec.y - startVec.y;

	return result;
}

float Length(const Vector2& one, const Vector2& two)
{
	Vector2 result{};
	float length = 0;

	result = LengthDis(one, two);

	length = sqrtf(powf(result.x, 2) + powf(result.y, 2));

	return length;
}

void Normalize(Vector2& vec)
{
	float length;
	length = sqrtf(powf(vec.x, 2) + powf(vec.y, 2));

	if (length != 0) {
		vec.x = vec.x / length;
		vec.y = vec.y / length;
	}
}

bool IsCircleHit(const Vector2& one, const Vector2& two, const float& radius1, const float& radius2)
{
	float leng = Length(one, two);
	float rad = radius1 + radius2;
	if (leng < rad)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Lerp(float start, float end, float t)
{
	return (1 - t) * start + t * end;
}

Vector2 Lerp(Vector2 start, Vector2 end, float t)
{
	Vector2 result{};

	result.x = (1 - t) * start.x + t * end.x;
	result.y = (1 - t) * start.y + t * end.y;

	return result;
}

Quad QuadPos(const Vector2& pos, const float& radius)
{
	Quad result{};
	result.lt = { pos.x - radius,pos.y + radius };
	result.rt = { pos.x + radius,result.lt.y };
	result.lb = { result.lt.x,pos.y - radius };
	result.rb = { result.rt.x,result.lb.y };
	return result;
}
