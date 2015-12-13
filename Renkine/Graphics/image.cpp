#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include "image.h"

namespace renkine
{
	bool ImageLoader::LoadImage (const char *filepath, Image &image)
	{
		image.bytes = NULL;
		image.width = 0;
		image.height = 0;
		image.bytes_per_pixel = 0;

		image->bytes = stbi_load (filepath, image.width, image.height, image.bytes_per_pixel, STBI_rgb_alpha);
		if (image->bytes == NULL)
		{
			return false;
		}

		return true;
	}

	bool ImageLoader::FreeImage (Image &image)
	{
		if (image.bytes != NULL)
		{
			stbi_image_free (image.bytes);
			image.bytes = NULL;
			image.width = 0;
			image.height = 0;
			image.bytes_per_pixel = 0;
		}
	}
}
