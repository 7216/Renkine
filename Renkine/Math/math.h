#define _USE_MATH_DEFINES
#include <math.h>

namespace renkine
{
	inline float toRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}
	inline float lerp(float from, float to, float alpha)
	{
		return (1.0f - alpha) * from + alpha * to;
	}
	inline float min(float a, float b)
	{
		return (a < b) ? a : b;
	}
	inline float max(float a, float b)
	{
		return (a > b) ? a : b;
	}
	inline float clamp(float value, float min, float max)
	{
		return (value < min ? min : value > max ? max : value);
	}
}