#ifndef RENKINE_GRAPHICS_IMAGE_H
#define RENKINE_GRAPHICS_IMAGE_H

#include <Renkine/Types/types.h>

namespace renkine
{
	struct Image
	{
		u8	*bytes;
		int	width;
		int height;
		int	bytes_per_pixel;
	};

	class ImageLoader
	{
	public:
		static bool LoadImage (const char *filepath, Image &image);
		static bool FreeImage (Image &image);
	};
}

#endif // RENKINE_GRAPHICS_IMAGE_H
