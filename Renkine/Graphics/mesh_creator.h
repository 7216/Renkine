#ifndef RENKINE_GRAPHICS_MESH_CREATOR_H
#define RENKINE_GRAPHICS_MESH_CREATOR_H

#include <Renkine/types/graphics_types.h>

namespace renkine
{
	class MeshCreator2D
	{
	public:
		static void AddVertex	(Mesh2D *mesh, Vector2 v);
		static void AddUVCoord	(Mesh2D *mesh, Vector2 v);
		static void AddFace		(Mesh2D *mesh, u32 p0, u32 p1, u32 p2);
		static void AddFace		(Mesh2D *mesh, u32 p0, u32 p1, u32 p2, u32 p3);

		static Mesh2D *CreateEmptyMesh ();
		static Mesh2D *CreateQuadMesh  (Vector2 size);
		static void	  DestroyMesh	   (Mesh2D *mesh);
	};
}

#endif // RENKINE_GRAPHICS_MESH_CREATOR_H
