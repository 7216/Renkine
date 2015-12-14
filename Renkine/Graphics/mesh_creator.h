#ifndef RENKINE_GRAPHICS_MESH_CREATOR_H
#define RENKINE_GRAPHICS_MESH_CREATOR_H

#include <Renkine/types/graphics_types.h>

namespace renkine
{
	class MeshCreator
	{
	public:
		static void AddVertex	(Mesh *mesh, Vector3 v);
		static void AddUVCoord	(Mesh *mesh, Vector2 v);
		static void AddFace		(Mesh *mesh, u32 p0, u32 p1, u32 p2);
		static void AddFace		(Mesh *mesh, u32 p0, u32 p1, u32 p2, u32 p3);

		static Mesh *CreateEmptyMesh ();
		static Mesh *CreateQuadMesh  (Vector2 size);
		static void	 DestroyMesh	 (Mesh *mesh);
	};
}

#endif // RENKINE_GRAPHICS_MESH_CREATOR_H
