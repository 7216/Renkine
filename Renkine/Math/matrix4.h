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
		};

		Matrix4 ();
		Matrix4 (float diagonal);

		void Identity ();

		void Orthographic (float left, float right, float top, float bottom, float near, float far);
		void Perspective (float fov, float aspectRatio, float near, float far);

		void Translate (const Vector3 translation);
		void Rotate (const Vector3 axis, float angle);
		void Scale (const Vector3 scale);

		void Multiply (const Matrix4 &other);

		Matrix4 operator * (const Matrix4 &other);
		void operator *= (const Matrix4 &other);
	};
}

#endif  // RENKINE_MATH_MATRIX4_H
