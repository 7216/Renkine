#ifndef RENKINE_MATH_MATH_H
#define RENKINE_MATH_MATH_H

#define _USE_MATH_DEFINES
#include <math.h>

namespace renkine
{
	class Math
	{
	public:
		static inline float toRadians(float degrees)
		{
			return degrees * ((float)M_PI / 180.0f);
		}

		static inline float lerp(float from, float to, float alpha)
		{
			return (1.0f - alpha) * from + alpha * to;
		}
		
		static inline float min(float a, float b)
		{
			return (a < b) ? a : b;
		}
		
		static inline float max(float a, float b)
		{
			return (a > b) ? a : b;
		}

		static inline float clamp(float value, float min, float max)
		{
			return (value < min ? min : value > max ? max : value);
		}
	};
}

#endif // RENKINE_MATH_MATH_H
