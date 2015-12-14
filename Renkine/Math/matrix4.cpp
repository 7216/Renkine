#include "matrix4.h"
#include "math.h"
#include <math.h>
namespace renkine
{
	Matrix4::Matrix4 ()
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			elements[i] = 0.0f;
		}
	}

	const Matrix4 Matrix4::Identity ()
	{
		Matrix4 identity;
		identity.elements[0 + 0 * 4] = 1.0f;
		identity.elements[1 + 1 * 4] = 1.0f;
		identity.elements[2 + 2 * 4] = 1.0f;
		identity.elements[3 + 3 * 4] = 1.0f;

		return identity;
	}

	Matrix4 Matrix4::Orthographic (float left, float right, float top, float bottom, float near, float far)
	{
		Matrix4 matrix = Matrix4::Identity ();
		matrix.elements[0 + 0 * 4] = 2.0f / (right - left);
		matrix.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		matrix.elements[2 + 2 * 4] = 2.0f / (near - far);

		matrix.elements[0 + 3 * 4] = (left + right) / (left - right);
		matrix.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		matrix.elements[2 + 3 * 4] = (far + near) / (far - near);

		return matrix;
	}

	Matrix4 Matrix4::Perspective (float fov, float aspectRatio, float near, float far)
	{
		float q = 1.0f / tanf (Math::ToRadians (fov * 0.5f));
		float a = q / aspectRatio;
		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		Matrix4 matrix = Matrix4::Identity ();
		matrix.elements[0 + 0 * 4] = a;
		matrix.elements[1 + 1 * 4] = q;
		matrix.elements[2 + 2 * 4] = b;
		matrix.elements[3 + 2 * 4] = -1.f;
		matrix.elements[2 + 3 * 4] = c;

		return matrix;
	}

	Matrix4 Matrix4::Translate (const Vector3 translation)
	{
		Matrix4 matrix = Matrix4::Identity ();
		matrix.elements[0 + 3 * 4] = translation.x;
		matrix.elements[1 + 3 * 4] = translation.y;
		matrix.elements[2 + 3 * 4] = translation.z;

		return matrix;
	}

	Matrix4 Matrix4::Rotate (const Vector3 axis, float angle)
	{
		float radians = Math::ToRadians (angle);
		float cosine = cosf (radians);
		float sine = sinf (radians);
	
		float oneMinusCosine = 1.0f - cosine;

		Matrix4 matrix = Matrix4::Identity ();
		matrix.elements[0 + 0 * 4] = axis.x * oneMinusCosine + cosine;
		matrix.elements[1 + 0 * 4] = axis.y * axis.x * oneMinusCosine + axis.z * sine;
		matrix.elements[2 + 0 * 4] = axis.x * axis.z * oneMinusCosine - axis.y * sine;

		matrix.elements[0 + 1 * 4] = axis.x * axis.y * oneMinusCosine - axis.z * sine;
		matrix.elements[1 + 1 * 4] = axis.y * oneMinusCosine + cosine;
		matrix.elements[2 + 1 * 4] = axis.y * axis.z * oneMinusCosine + axis.x * sine;

		matrix.elements[0 + 2 * 4] = axis.x * axis.z * oneMinusCosine + axis.y * sine;
		matrix.elements[1 + 2 * 4] = axis.y * axis.z * oneMinusCosine - axis.x * sine;
		matrix.elements[2 + 2 * 4] = axis.z * oneMinusCosine + cosine;

		return matrix;
	}

	Matrix4 Matrix4::Scale (const Vector3 scale)
	{
		Matrix4 matrix = Matrix4::Identity ();
		matrix.elements[0 + 0 * 4] = scale.x;
		matrix.elements[1 + 1 * 4] = scale.y;
		matrix.elements[2 + 2 * 4] = scale.z;

		return matrix;
	}

	Matrix4 Matrix4::Skew (const Vector3 skew)
	{
		Matrix4 matrix = Matrix4::Identity ();
		matrix.m01 = skew.x;
		matrix.m10 = skew.y;
		matrix.m02 = skew.z;
		matrix.m12 = skew.z;
		return matrix;
	}


	void Matrix4::Multiply (const Matrix4 &other)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; i++)
				{
					sum += elements[x + i * 4] * other.elements[i + y * 4];
				}
				elements[x + y * 4] = sum;
			}
		}
	}

	Matrix4 Matrix4::operator * (const Matrix4 &other)
	{
		Matrix4 result = *this;
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int i = 0; i < 4; i++)
				{
					sum += result.elements[x + i * 4] * other.elements[i + y * 4];
				}
				result.elements[x + y * 4] = sum;
			}
		}
		return result;
	}
	void Matrix4::operator *= (const Matrix4 &other)
	{
		Multiply (other);
	}
}