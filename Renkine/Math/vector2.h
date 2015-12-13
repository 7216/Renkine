#ifndef RENKINE_MATH_VECTOR2_H
#define RENKINE_MATH_VECTOR2_H

#include <Renkine/Math/math.h>

namespace renkine
{
	struct Vector2
	{
		float x, y;

		Vector2();
		Vector2(float x, float y);

		Vector2 Add (const float &other);
		Vector2 Substract (const float &other);
		Vector2 Multiply (const float &other);
		Vector2 Divide (const float &other);

		Vector2 Add	(const Vector2 &other);
		Vector2 Substract (const Vector2 &other);
		Vector2 Multiply (const Vector2 &other);
		Vector2 Divide (const Vector2 &other);

		float Magnitude ();
		float Length ();

		void SetMagnitude (float magnitude);
		void SetLength (float length);

		float Dot ();

		float Angle (Math::ANGLE_TYPE angle_type);

		void Normalize ();
		
		void Lerp (const Vector2 &other, float alpha);
		void Clamp (const Vector2 &min, const Vector2 &max);

		void Rotate (const float angle);

		bool Equals (const Vector2 &other );
		bool Equals (const float &other);

		Vector2 operator + (const float other);
		Vector2 operator - (const float other);
		Vector2 operator * (const float other);
		Vector2 operator / (const float other);

		bool operator == (const float other);
		bool operator != (const float other);

		void operator += (const float other);
		void operator -= (const float other);
		void operator *= (const float other);
		void operator /= (const float other);

		Vector2 operator + (const Vector2 &other);
		Vector2 operator - (const Vector2 &other);
		Vector2 operator * (const Vector2 &other);
		Vector2 operator / (const Vector2 &other);

		bool operator == (const Vector2 &other);
		bool operator != (const Vector2 &other);
						 
		void operator += (const Vector2 &other);
		void operator -= (const Vector2 &other);
		void operator *= (const Vector2 &other);
		void operator /= (const Vector2 &other);

		//friend std::ostream& operator<<(std::ostream& stream, const Vector2 &vector);
	};
}

#endif  // RENKINE_MATH_VECTOR2_H
