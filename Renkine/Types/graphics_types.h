#ifndef RENKINE_TYPES_GRAPHICS_TYPES_H
#define RENKINE_TYPES_GRAPHICS_TYPES_H

#include <Renkine/Types/types.h>

namespace renkine
{
	struct Vector2
	{
		float x, y;	
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
		u32 _vbo;
		u32 _ebo;
		
		Mesh2D *mesh;
	};
}

#endif // RENKINE_TYPES_GRAPHICS_TYPES_H