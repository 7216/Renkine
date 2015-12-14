#include <Renkine\Utils\model_loader.h>

namespace renkine
{
	Mesh *ModelLoader::LoadOBJ (char filepath[])
	{
		Mesh *objMesh = MeshCreator::CreateEmptyMesh ();

		FILE *file = fopen (filepath, "rt");

		if (file == NULL)
		{
			printf ("Something is super fucked with your OBJ bro.");
		}

		char line[1024];

		while (fgets (line, 1024, file))
		{
			if (line[0] == 'v', line[1] == ' ') // Vertice
			{
				float x = .0f, y = .0f, z = .0f;
				scanf (line, "v %f %f %f", &x, &y, &z);
				MeshCreator::AddVertex (objMesh, Vector3 (x, y, z));
			}
			if (line[0] == 'v', line[1] == 't') // UV
			{
				float u = .0f, v = .0f;
				scanf (line, "vt %f %f", &u, &v);
				MeshCreator::AddUVCoord (objMesh, Vector2 (u, v));
			}
			/*
			if (line[0] == 'v', line[1] == 'n') // Normal
			{
				float x = .0f, y = .0f, z = .0f;
				scanf (line, "v %f %f %f", &x, &y, &z);
				MeshCreator::AddVertex (objMesh, Vector3 (x, y, z));
			}
			*/
			if (line[0] == 'f', line[1] == ' ') // Indices
			{
				renkine::u32 p1, p2, p3;
				scanf (line, "vt %i/%i/%i %i/%i/%i %i/%i/%i", &p1, &p2, &p3);
				MeshCreator::AddFace (objMesh, p1, p2, p3);
			}
		}
		return objMesh;
	}
}