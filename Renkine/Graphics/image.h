#ifndef RENKINE_GRAPHICS_IMAGE_H
#define RENKINE_GRAPHICS_IMAGE_H

#include <Renkine/Types/types.h>

namespace renkine
{
	struct Image
	{
		u8	*bytes;
		u32	width;
		u32 height;
		u8 	bytes_per_pixel;
	};

	class ImageLoader
	{
	public:
		static bool LoadImage (const char *filepath, Image &image);
		static bool FreeImage (Image &image);
	};
}

#endif // RENKINE_GRAPHICS_IMAGE_H
