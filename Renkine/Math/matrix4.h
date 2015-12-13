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

		Matrix4 Identity ();

		Matrix4 Orthographic (float left, float right, float top, float bottom, float near, float far);
		Matrix4 Perspective (float fov, float aspectRatio, float near, float far);

		Matrix4 Translate (const Vector3 translation);
		Matrix4 Rotate (const Vector3 axis, float angle);
		Matrix4 Scale (const Vector3 scale);

		void Multiply (const Matrix4 &other);

		Matrix4 operator * (const Matrix4 &other);
		void operator *= (const Matrix4 &other);
	};
}

#endif  // RENKINE_MATH_Matrix4_H
