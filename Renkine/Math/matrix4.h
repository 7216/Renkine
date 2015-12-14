#ifndef RENKINE_MATH_MATRIX4_H
#define RENKINE_MATH_MATRIX4_H

#include "vector4.h"
#include "vector3.h"

namespace renkine
{
	struct Matrix4
	{
		union {
			float elements[4 * 4];
			struct {
				Vector4 columns[4];
			};

			struct {
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};
		};

		Matrix4 ();

		static const Matrix4 Identity ();

		static Matrix4 Orthographic (float left, float right, float top, float bottom, float near, float far);
		static Matrix4 Perspective (float fov, float aspectRatio, float near, float far);

		static Matrix4 Translate (const Vector3 translation);
		static Matrix4 Rotate (const Vector3 axis, float angle);
		static Matrix4 Scale (const Vector3 scale);
		static Matrix4 Skew	(const Vector3 skew);

		void Multiply (const Matrix4 &other);

		Matrix4 operator * (const Matrix4 &other);
		void operator *= (const Matrix4 &other);
	};
}

#endif  // RENKINE_MATH_MATRIX4_H
