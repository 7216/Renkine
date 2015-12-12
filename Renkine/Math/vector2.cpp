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

	Vector2 Vector2::Add (const float &other)
	{
		return Vector2 (x + other, y + other);
	}
	Vector2 Vector2::Substract (const float &other)
	{
		return Vector2 (x - other, y - other);
	}
	Vector2 Vector2::Multiply (const float &other)
	{
		return Vector2 (x * other, y * other);
	}
	Vector2 Vector2::Divide (const float &other)
	{
		return Vector2 (x / other, y / other);
	}

	Vector2 Vector2::Add (const Vector2 &other)
	{
		return Vector2 (x + other.x, y + other.y);
	}
	Vector2 Vector2::Substract (const Vector2 &other)
	{
		return Vector2 (x - other.x, y - other.y);
	}
	Vector2 Vector2::Multiply (const Vector2 &other)
	{
		return Vector2 (x * other.x, y * other.y);
	}
	Vector2 Vector2::Divide (const Vector2 &other)
	{
		return Vector2 (x / other.x, y / other.y);
	}

	void Vector2::Normalize ()
	{
		float mag = Magnitude ();
		x = x / mag;
		y = y / mag;
	}

	float Vector2::Magnitude ()
	{
		return sqrtf ((x*x) + (y*y));
	}
	float Vector2::Length ()
	{
		return Magnitude ();
	}
	void Vector2::SetMagnitude (float magnitude)
	{
		Normalize ();
		*this *= magnitude;
	}
	void Vector2::SetLength (float length)
	{
		SetMagnitude (length);
	}

	float Vector2::Dot()
	{
		return ((x*x) + (y*y));
	}

	float Vector2::Angle (Math::ANGLE_TYPE angle_type)
	{
		if (angle_type)
			return atan2 (y, x);
		else
			return Math::ToRadians(atan2 (y, x));
	}

	void Vector2::Lerp (const Vector2 &other, float alpha)
	{
		x = renkine::Math::lerp (x, other.x, alpha);
		y = renkine::Math::lerp (y, other.y, alpha);
	}
	void Vector2::Clamp (const Vector2 &min, const Vector2 &max)
	{
		x = renkine::Math::clamp (x, min.x, max.x);
		y = renkine::Math::clamp (y, min.y, max.y);
	}

	void Vector2::Rotate (const float angle)
	{
		float mag = Magnitude ();
		float ang = Angle (Math::ANGLE_TYPE::RADIANS) + Math::ToRadians(angle);

		x = cos (ang) * mag;
		y = sin (ang) * mag;
	}

	bool Vector2::Equals (const float &other)
	{
		return x == other && y == other;
	}
	bool Vector2::Equals (const Vector2 &other)
	{
		return x == other.x && y == other.y;
	}

	Vector2 Vector2::operator + (const float &other)
	{
		return Add (other);
	}
	Vector2 Vector2::operator - (const float &other)
	{
		return Substract (other);
	}
	Vector2 Vector2::operator * (const float &other)
	{
		return Multiply (other);
	}
	Vector2 Vector2::operator / (const float &other)
	{
		return Divide (other);
	}

	bool Vector2::operator == (const float &other)
	{
		return Equals (other);
	}
	bool Vector2::operator != (const float &other)
	{
		return !(*this == other);
	}

	void Vector2::operator += (const float &other)
	{
		x += other;
		y += other;
	}
	void Vector2::operator -= (const float &other)
	{
		x -= other;
		y -= other;
	}
	void Vector2::operator *= (const float &other)
	{
		x *= other;
		y *= other;
	}
	void Vector2::operator /= (const float &other)
	{
		x /= other;
		y /= other;
	}

	Vector2 Vector2::operator + (const Vector2 &other)
	{
		return Add (other);
	}
	Vector2 Vector2::operator - (const Vector2 &other)
	{
		return Substract (other);
	}
	Vector2 Vector2::operator * (const Vector2 &other)
	{
		return Multiply (other);
	}
	Vector2 Vector2::operator / (const Vector2 &other)
	{
		return Divide (other);
	}

	bool Vector2::operator == (const Vector2 &other)
	{
		return Equals (other);
	}
	bool Vector2::operator != (const Vector2 &other)
	{
		return !(*this == other);
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