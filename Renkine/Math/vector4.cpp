#include "Vector4.h"

#include <math.h>
#include "math.h"

namespace renkine
{
	Vector4::Vector4 ()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector4::Vector4 (float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4 Vector4::Add (const float &other)
	{
		return Vector4 (x + other, y + other, z + other, w + other);
	}
	Vector4 Vector4::Substract (const float &other)
	{
		return Vector4 (x - other, y - other, z - other, w - other);
	}
	Vector4 Vector4::Multiply (const float &other)
	{
		return Vector4 (x * other, y * other, z * other, w * other);
	}
	Vector4 Vector4::Divide (const float &other)
	{
		return Vector4 (x / other, y / other, z / other, w / other);
	}

	Vector4 Vector4::Add (const Vector4 &other)
	{
		return Vector4 (x + other.x, y + other.y, z + other.z, w + other.w);
	}
	Vector4 Vector4::Substract (const Vector4 &other)
	{
		return Vector4 (x - other.x, y - other.y, z - other.z, w - other.w);
	}
	Vector4 Vector4::Multiply (const Vector4 &other)
	{
		return Vector4 (x * other.x, y * other.y, z * other.z, w * other.w);
	}
	Vector4 Vector4::Divide (const Vector4 &other)
	{
		return Vector4 (x / other.x, y / other.y, z / other.z, w / other.w);
	}

	void Vector4::Normalize ()
	{
		float mag = Magnitude ();
		x = x / mag;
		y = y / mag;
		z = z / mag;
		w = w / mag;
	}

	float Vector4::Magnitude ()
	{
		return sqrtf ((x*x) + (y*y) + (z*z) + (w*w));
	}
	float Vector4::Length ()
	{
		return Magnitude ();
	}
	void Vector4::SetMagnitude (float magnitude)
	{
		Normalize ();
		*this *= magnitude;
	}
	void Vector4::SetLength (float length)
	{
		SetMagnitude (length);
	}

	float Vector4::Dot()
	{
		return ((x*x) + (y*y) + (z*z) + (w*w));
	}

	float Vector4::Angle (Math::ANGLE_TYPE angle_type)
	{
		return 0; // TODO: implement it yo
	}

	void Vector4::Lerp (const Vector4 &other, float alpha)
	{
		x = renkine::Math::lerp (x, other.x, alpha);
		y = renkine::Math::lerp (y, other.y, alpha);
		z = renkine::Math::lerp (z, other.z, alpha);
		w = renkine::Math::lerp (w, other.w, alpha);
	}
	void Vector4::Clamp (const Vector4 &min, const Vector4 &max)
	{
		x = renkine::Math::clamp (x, min.x, max.x);
		y = renkine::Math::clamp (y, min.y, max.y);
		z = renkine::Math::clamp (z, min.z, max.z);
		w = renkine::Math::clamp (w, min.w, max.w);
	}

	void Vector4::Rotate (const float angle)
	{
		// TODO: implement this too damn son.
	}

	bool Vector4::Equals (const float &other)
	{
		return x == other && y == other && z == other && w == other;
	}
	bool Vector4::Equals (const Vector4 &other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	Vector4 Vector4::operator + (const float &other)
	{
		return Add (other);
	}
	Vector4 Vector4::operator - (const float &other)
	{
		return Substract (other);
	}
	Vector4 Vector4::operator * (const float &other)
	{
		return Multiply (other);
	}
	Vector4 Vector4::operator / (const float &other)
	{
		return Divide (other);
	}

	bool Vector4::operator == (const float &other)
	{
		return Equals (other);
	}
	bool Vector4::operator != (const float &other)
	{
		return !(*this == other);
	}

	void Vector4::operator += (const float &other)
	{
		x += other;
		y += other;
		z += other;
		w += other;
	}
	void Vector4::operator -= (const float &other)
	{
		x -= other;
		y -= other;
		z -= other;
		w -= other;
	}
	void Vector4::operator *= (const float &other)
	{
		x *= other;
		y *= other;
		z *= other;
		w *= other;
	}
	void Vector4::operator /= (const float &other)
	{
		x /= other;
		y /= other;
		z /= other;
		w /= other;
	}

	Vector4 Vector4::operator + (const Vector4 &other)
	{
		return Add (other);
	}
	Vector4 Vector4::operator - (const Vector4 &other)
	{
		return Substract (other);
	}
	Vector4 Vector4::operator * (const Vector4 &other)
	{
		return Multiply (other);
	}
	Vector4 Vector4::operator / (const Vector4 &other)
	{
		return Divide (other);
	}

	bool Vector4::operator == (const Vector4 &other)
	{
		return Equals (other);
	}
	bool Vector4::operator != (const Vector4 &other)
	{
		return !(*this == other);
	}

	void Vector4::operator += (const Vector4 &other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
	}
	void Vector4::operator -= (const Vector4 &other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
	}
	void Vector4::operator *= (const Vector4 &other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
	}
	void Vector4::operator /= (const Vector4 &other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
	}

}