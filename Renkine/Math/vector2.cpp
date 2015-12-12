#include "Vector2.h"

#include <math.h>
#include "math.h"

namespace renkine
{
	Vector2::Vector2 ()
	{
		x = 0.0f;
		y = 0.0f;
	}

	Vector2::Vector2 (float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 Vector2::add (const Vector2 &other)
	{
		return Vector2 (x + other.x, y + other.y);
	}
	Vector2 Vector2::substract (const Vector2 &other)
	{
		return Vector2 (x - other.x, y - other.y);
	}
	Vector2 Vector2::multiply (const Vector2 &other)
	{
		return Vector2 (x * other.x, y * other.y);
	}
	Vector2 Vector2::divide (const Vector2 &other)
	{
		return Vector2 (x / other.x, y / other.y);
	}

	void Vector2::normalize ()
	{
		float mag = magnitude ();
		x = x / mag;
		y = y / mag;
	}

	float Vector2::magnitude ()
	{
		return sqrtf ((x*x) + (y*y));
	}
	float Vector2::length ()
	{
		return magnitude ();
	}
	float Vector2::dot()
	{
		return ((x*x) + (y*y));
	}
	

	void Vector2::lerp (const Vector2 &other, float alpha)
	{
		x = renkine::Math::lerp (x, other.x, alpha);
		y = renkine::Math::lerp (y, other.y, alpha);
	}
	void Vector2::clamp (const Vector2 &min, const Vector2 &max)
	{
		x = renkine::Math::clamp (x, min.x, max.x);
		y = renkine::Math::clamp (y, min.y, max.y);
	}

	bool Vector2::equals (const Vector2 &other)
	{
		return x == other.x && y == other.y;
	}

	Vector2 Vector2::operator + (const Vector2 &other)
	{
		return add (other);
	}
	Vector2 Vector2::operator - (const Vector2 &other)
	{
		return substract (other);
	}
	Vector2 Vector2::operator * (const Vector2 &other)
	{
		return multiply (other);
	}
	Vector2 Vector2::operator / (const Vector2 &other)
	{
		return divide (other);
	}

	bool Vector2::operator == (const Vector2 &other)
	{
		return equals (other);
	}
	bool Vector2::operator != (const Vector2 &other)
	{
		return !(equals (other));
	}

	void Vector2::operator += (const Vector2 &other)
	{
		x += other.x;
		y += other.y;
	}
	void Vector2::operator -= (const Vector2 &other)
	{
		x -= other.x;
		y -= other.y;
	}
	void Vector2::operator *= (const Vector2 &other)
	{
		x *= other.x;
		y *= other.y;
	}
	void Vector2::operator /= (const Vector2 &other)
	{
		x /= other.x;
		y /= other.y;
	}

}