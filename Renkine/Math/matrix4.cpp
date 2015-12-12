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
	Matrix4::Matrix4 (float diagonal)
	{
		for (int i = 0; i < 4 * 4; i++)
		{
			elements[i] = 0.0f;
		}
		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4 Matrix4::Identity ()
	{
		return Matrix4 (1.0f);
	}

	Matrix4 Matrix4::Orthographic (float left, float right, float top, float bottom, float near, float far)
	{
		Matrix4 result (1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);

		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);

		return result;
	}
	Matrix4 Matrix4::Perspective (float fov, float aspectRatio, float near, float far)
	{
		Matrix4 result (1.0f);

		float q = 1.0f / tan (Math::ToRadians (fov * .5f));
		float a = q / aspectRatio;
		float b = (near + far) / (near - far);
		float c = (2.0f * near * far) / (near - far);

		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		result.elements[3 + 2 * 4] = -1.f;
		result.elements[2 + 3 * 4] = c;

		return result;
	}

	Matrix4 Matrix4::Translate (const Vector3 translation)
	{
		Matrix4 result (1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}
	Matrix4 Matrix4::Rotate (const Vector3 axis, float angle)
	{
		Matrix4 result (1.0f);

		float radians = Math::ToRadians (angle);
		float cosine = cos (radians);
		float sine = sin (radians);



		float oneMinusCosine = 1.0f - cosine;

		result.elements[0 + 0 * 4] = axis.x * oneMinusCosine + cosine;
		result.elements[1 + 0 * 4] = axis.y * axis.x * oneMinusCosine + axis.z * sine;
		result.elements[2 + 0 * 4] = axis.x * axis.z * oneMinusCosine - axis.y * sine;

		result.elements[0 + 1 * 4] = axis.x * axis.y * oneMinusCosine - axis.z * sine;
		result.elements[1 + 1 * 4] = axis.y * oneMinusCosine + cosine;
		result.elements[2 + 1 * 4] = axis.y * axis.z * oneMinusCosine + axis.x * sine;

		result.elements[0 + 2 * 4] = axis.x * axis.z * oneMinusCosine + axis.y * sine;
		result.elements[1 + 2 * 4] = axis.y * axis.z * oneMinusCosine - axis.x * sine;
		result.elements[2 + 2 * 4] = axis.z * oneMinusCosine + cosine;

		return result;
	}
	Matrix4 Matrix4::Scale (const Vector3 scale)
	{
		Matrix4 result (1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
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