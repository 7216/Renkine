#include "Vector3.h"

#include <math.h>
#include "math.h"

namespace renkine
{
	Vector3::Vector3 ()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3::Vector3 (float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 Vector3::Add (const float &other)
	{
		return Vector3 (x + other, y + other, z + other);
	}
	Vector3 Vector3::Substract (const float &other)
	{
		return Vector3 (x - other, y - other, z - other);
	}
	Vector3 Vector3::Multiply (const float &other)
	{
		return Vector3 (x * other, y * other, z * other);
	}
	Vector3 Vector3::Divide (const float &other)
	{
		return Vector3 (x / other, y / other, z / other);
	}

	Vector3 Vector3::Add (const Vector3 &other)
	{
		return Vector3 (x + other.x, y + other.y, z + other.z);
	}
	Vector3 Vector3::Substract (const Vector3 &other)
	{
		return Vector3 (x - other.x, y - other.y, z - other.z);
	}
	Vector3 Vector3::Multiply (const Vector3 &other)
	{
		return Vector3 (x * other.x, y * other.y, z * other.z);
	}
	Vector3 Vector3::Divide (const Vector3 &other)
	{
		return Vector3 (x / other.x, y / other.y, z / other.z);
	}

	void Vector3::Normalize ()
	{
		float mag = Magnitude ();
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}

	float Vector3::Magnitude ()
	{
		return sqrtf ((x*x) + (y*y) + (z*z));
	}
	float Vector3::Length ()
	{
		return Magnitude ();
	}
	void Vector3::SetMagnitude (float magnitude)
	{
		Normalize ();
		*this *= magnitude;
	}
	void Vector3::SetLength (float length)
	{
		SetMagnitude (length);
	}

	float Vector3::Dot()
	{
		return ((x*x) + (y*y) + (z*z));
	}

	float Vector3::Angle (Math::ANGLE_TYPE angle_type)
	{
		return 0; // TODO: implement it yo
	}

	void Vector3::Lerp (const Vector3 &other, float alpha)
	{
		x = renkine::Math::lerp (x, other.x, alpha);
		y = renkine::Math::lerp (y, other.y, alpha);
		z = renkine::Math::lerp (z, other.z, alpha);
	}
	void Vector3::Clamp (const Vector3 &min, const Vector3 &max)
	{
		x = renkine::Math::clamp (x, min.x, max.x);
		y = renkine::Math::clamp (y, min.y, max.y);
		z = renkine::Math::clamp (z, min.z, max.z);
	}

	void Vector3::Rotate (const float angle)
	{
		// TODO: implement this too damn son.
	}

	bool Vector3::Equals (const float &other)
	{
		return x == other && y == other && z == other;
	}
	bool Vector3::Equals (const Vector3 &other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	Vector3 Vector3::operator + (const float other)
	{
		return Add (other);
	}
	Vector3 Vector3::operator - (const float other)
	{
		return Substract (other);
	}
	Vector3 Vector3::operator * (const float other)
	{
		return Multiply (other);
	}
	Vector3 Vector3::operator / (const float other)
	{
		return Divide (other);
	}

	bool Vector3::operator == (const float other)
	{
		return Equals (other);
	}
	bool Vector3::operator != (const float other)
	{
		return !(*this == other);
	}

	void Vector3::operator += (const float other)
	{
		x += other;
		y += other;
		z += other;
	}
	void Vector3::operator -= (const float other)
	{
		x -= other;
		y -= other;
		z -= other;
	}
	void Vector3::operator *= (const float other)
	{
		x *= other;
		y *= other;
		z *= other;
	}
	void Vector3::operator /= (const float other)
	{
		x /= other;
		y /= other;
		z /= other;
	}

	Vector3 Vector3::operator + (const Vector3 &other)
	{
		return Add (other);
	}
	Vector3 Vector3::operator - (const Vector3 &other)
	{
		return Substract (other);
	}
	Vector3 Vector3::operator * (const Vector3 &other)
	{
		return Multiply (other);
	}
	Vector3 Vector3::operator / (const Vector3 &other)
	{
		return Divide (other);
	}

	bool Vector3::operator == (const Vector3 &other)
	{
		return Equals (other);
	}
	bool Vector3::operator != (const Vector3 &other)
	{
		return !(*this == other);
	}

	void Vector3::operator += (const Vector3 &other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}
	void Vector3::operator -= (const Vector3 &other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}
	void Vector3::operator *= (const Vector3 &other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
	}
	void Vector3::operator /= (const Vector3 &other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
	}

}