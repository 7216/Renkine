#ifndef RENKINE_MATH_VECTOR3_H
#define RENKINE_MATH_VECTOR3_H

#include <Renkine/Math/math.h>

namespace renkine
{
	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(float x, float y, float z);

		Vector3 Add (const float &other);
		Vector3 Substract (const float &other);
		Vector3 Multiply (const float &other);
		Vector3 Divide (const float &other);

		Vector3 Add	(const Vector3 &other);
		Vector3 Substract (const Vector3 &other);
		Vector3 Multiply (const Vector3 &other);
		Vector3 Divide (const Vector3 &other);

		float Magnitude ();
		float Length ();

		void SetMagnitude (float magnitude);
		void SetLength (float length);

		float Dot ();

		float Angle (Math::ANGLE_TYPE angle_type);

		void Normalize ();
		
		void Lerp (const Vector3 &other, float alpha);
		void Clamp (const Vector3 &min, const Vector3 &max);

		void Rotate (const float angle);

		bool Equals (const Vector3 &other );
		bool Equals (const float &other);

		Vector3 operator + (const float other);
		Vector3 operator - (const float other);
		Vector3 operator * (const float other);
		Vector3 operator / (const float other);

		bool operator == (const float other);
		bool operator != (const float other);

		void operator += (const float other);
		void operator -= (const float other);
		void operator *= (const float other);
		void operator /= (const float other);

		Vector3 operator + (const Vector3 &other);
		Vector3 operator - (const Vector3 &other);
		Vector3 operator * (const Vector3 &other);
		Vector3 operator / (const Vector3 &other);

		bool operator == (const Vector3 &other);
		bool operator != (const Vector3 &other);
						 
		void operator += (const Vector3 &other);
		void operator -= (const Vector3 &other);
		void operator *= (const Vector3 &other);
		void operator /= (const Vector3 &other);

		//friend std::ostream& operator<<(std::ostream& stream, const Vector3 &vector);
	};
}

#endif  // RENKINE_MATH_VECTOR3_H
