#ifndef RENKINE_GRAPHICS_GRAPHICS_H
#define RENKINE_GRAPHICS_GRAPHICS_H

#include <Renkine/Types/graphics_types.h>

namespace renkine
{
	class Graphics
	{
	public:
		static void SetProjectionMatrix (float *matrix);

		static void Clear (RGB color);
		static void Clear (RGBf color);
	};
}

#endif // RENKINE_GRAPHICS_GRAPHICS_H
