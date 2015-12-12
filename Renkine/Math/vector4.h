#ifndef RENKINE_MATH_VECTOR4_H
#define RENKINE_MATH_VECTOR4_H

namespace renkine
{
	struct Vector4
	{
		float x, y, z, w;

		Vector4();
		Vector4(float x, float y, float z, float w);

		Vector4 Add (const float &other);
		Vector4 Substract (const float &other);
		Vector4 Multiply (const float &other);
		Vector4 Divide (const float &other);

		Vector4 Add	(const Vector4 &other);
		Vector4 Substract (const Vector4 &other);
		Vector4 Multiply (const Vector4 &other);
		Vector4 Divide (const Vector4 &other);

		float Magnitude ();
		float Length ();

		void SetMagnitude (float magnitude);
		void SetLength (float length);

		float Dot ();

		float Angle (Math::ANGLE_TYPE angle_type);

		void Normalize ();
		
		void Lerp (const Vector4 &other, float alpha);
		void Clamp (const Vector4 &min, const Vector4 &max);

		void Rotate (const float angle);

		bool Equals (const Vector4 &other );
		bool Equals (const float &other);

		Vector4 operator + (const float &other);
		Vector4 operator - (const float &other);
		Vector4 operator * (const float &other);
		Vector4 operator / (const float &other);

		bool operator == (const float &other);
		bool operator != (const float &other);

		void operator += (const float &other);
		void operator -= (const float &other);
		void operator *= (const float &other);
		void operator /= (const float &other);

		Vector4 operator + (const Vector4 &other);
		Vector4 operator - (const Vector4 &other);
		Vector4 operator * (const Vector4 &other);
		Vector4 operator / (const Vector4 &other);

		bool operator == (const Vector4 &other);
		bool operator != (const Vector4 &other);
						 
		void operator += (const Vector4 &other);
		void operator -= (const Vector4 &other);
		void operator *= (const Vector4 &other);
		void operator /= (const Vector4 &other);

		//friend std::ostream& operator<<(std::ostream& stream, const Vector4 &vector);
	};
}

#endif  // RENKINE_MATH_VECTOR4_H
