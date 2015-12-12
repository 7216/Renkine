#ifndef RENKINE_TYPES_GRAPHICS_TYPES_H
#define RENKINE_TYPES_GRAPHICS_TYPES_H

#include <Renkine/Types/types.h>
#include <Renkine/Math/vector2.h>

namespace renkine
{
	struct RGB
	{
		u8 r, g, b;
		RGB (u8 r = 0, u8 g = 0, u8 b = 0) : r (r), g (g), b (b) {}
	};

	struct RGBf
	{
		float r, g, b;
		RGBf (float r = 0, float g = 0, float b = 0) : r (r), g (g), b (b) {}
	};

	struct RGBA
	{
		u8 r, g, b, a;
		RGBA (u8 r = 0, u8 g = 0, u8 b = 0, u8 a = 255) : r (r), g (g), b (b), a (a) {}
	};

	struct RGBAf
	{
		float r, g, b, a;
		RGBAf (float r = 0, float g = 0, float b = 0, float a = 255) : r (r), g (g), b (b), a (a) {}
	};


	struct Mesh2D
	{
		Vector2 	*vertices;
		Vector2 	*uv_coords;
		u32			*indices;

		u32			vertex_count;
		u32			uv_coord_count;
		u32			index_count;
	};

	struct Renderable2D
	{
		u32 _vertex_buffer;
		u32 _uv_buffer;
		u32 _element_buffer;
		
		Mesh2D *mesh;
	};
}

#endif // RENKINE_TYPES_GRAPHICS_TYPES_H