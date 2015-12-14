#include "mesh_creator.h"
#include <stdlib.h>


namespace renkine
{
	void MeshCreator::AddVertex (Mesh *mesh, Vector3 v)
	{
		if (mesh != NULL)
		{
			if (mesh->vertex_count == 0)
			{
				mesh->vertices = (Vector3 *) malloc (sizeof (Vector3));
			} else
			{
				mesh->vertices = (Vector3 *) realloc (mesh->vertices, sizeof (Vector3) * (mesh->vertex_count + 1));
			}

			mesh->vertices [mesh->vertex_count] = v;
			mesh->vertex_count ++;
		}
	}

	void MeshCreator::AddUVCoord (Mesh *mesh, Vector2 v)
	{
		if (mesh != NULL)
		{
			if (mesh->uv_coord_count == 0)
			{
				mesh->uv_coords = (Vector2 *) malloc (sizeof (Vector2));
			} else
			{
				mesh->uv_coords = (Vector2 *) realloc (mesh->uv_coords, sizeof (Vector2) * (mesh->uv_coord_count + 1));
			}

			mesh->uv_coords [mesh->uv_coord_count] = v;
			mesh->uv_coord_count ++;
		}
	}

	void MeshCreator::AddFace (Mesh *mesh, u32 p0, u32 p1, u32 p2)
	{
		if (mesh != NULL)
		{
			if (mesh->index_count == 0)
			{
				mesh->indices = (u32 *) malloc (sizeof (u32) * 3);
			} else
			{
				mesh->indices = (u32 *) realloc (mesh->indices, sizeof (u32) * (mesh->index_count + 3));
				if (mesh->indices == NULL)
				{
					exit (0);
				}
			}

			mesh->indices [mesh->index_count + 0] = p0;
			mesh->indices [mesh->index_count + 1] = p1;
			mesh->indices [mesh->index_count + 2] = p2;
			mesh->index_count += 3;
		}
	}

	void MeshCreator::AddFace (Mesh *mesh, u32 p0, u32 p1, u32 p2, u32 p3)
	{
		AddFace (mesh, p0, p1, p2);
		AddFace (mesh, p0, p2, p3);
	}

	Mesh *MeshCreator::CreateEmptyMesh ()
	{
		Mesh *mesh = NULL;
		mesh = (Mesh *) malloc (sizeof (Mesh));
		if (mesh == NULL)
		{
			return NULL;
		}

		mesh->vertices		 = NULL;
		mesh->uv_coords		 = NULL;
		mesh->vertex_count	 = 0;
		mesh->uv_coord_count = 0;
		mesh->index_count	 = 0;

		return mesh;
	}

	Mesh *MeshCreator::CreateQuadMesh  (Vector2 size)
	{
		Mesh *mesh = CreateEmptyMesh ();

		if (mesh == NULL)
		{
			return NULL;
		}

		size.x /= 2.0f;
		size.y /= 2.0f;

		AddVertex	(mesh, {-size.x, -size.y, 0.0f});
		AddVertex	(mesh, { size.x, -size.y, 0.0f});
		AddVertex	(mesh, { size.x,  size.y, 0.0f});
		AddVertex	(mesh, {-size.x,  size.y, 0.0f});
	
		AddUVCoord	(mesh, {0.0f, 0.0f});
		AddUVCoord	(mesh, {1.0f, 0.0f});
		AddUVCoord	(mesh, {1.0f, 1.0f});
		AddUVCoord	(mesh, {0.0f, 1.0f});

		AddFace		(mesh, 0, 1, 2, 3);
		return mesh;
	}

	void MeshCreator::DestroyMesh (Mesh * mesh)
	{
		if (mesh != NULL)
		{
			if (mesh->vertices	!= NULL) { free (mesh->vertices); }
			if (mesh->uv_coords != NULL) { free (mesh->uv_coords); }
			if (mesh->indices	!= NULL) { free (mesh->indices); }

			free (mesh);
			mesh = NULL;
		}
	}
}
