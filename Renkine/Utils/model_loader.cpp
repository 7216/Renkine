#include <Renkine\Utils\model_loader.h>

namespace renkine
{
	Mesh *ModelLoader::LoadOBJ (char filepath[])
	{
		Mesh *objMesh = MeshCreator::CreateEmptyMesh ();

		FILE *file = fopen (filepath, "r");

		if (file == NULL)
		{
			printf ("Something is super fucked with your OBJ bro.");
		}

		char line[1024] = "\0";

		while (fgets (line, 1024, file) != NULL)
		{
			if (line[0] == 'v' && line[1] == ' ') // Vertice
			{
				float x = .0f, y = .0f, z = .0f;
				sscanf (line, "v %f %f %f", &x, &y, &z);
				MeshCreator::AddVertex (objMesh, Vector3 (x, y, z));
			}
			else if (line[0] == 'v' && line[1] == 't') // UV
			{
				float u = .0f, v = .0f;
				sscanf (line, "vt %f %f", &u, &v);
				MeshCreator::AddUVCoord (objMesh, Vector2 (u, v));
			}
			/*
			if (line[0] == 'v' && line[1] == 'n') // Normal
			{
				float x = .0f, y = .0f, z = .0f;
				scanf (line, "v %f %f %f", &x, &y, &z);
				MeshCreator::AddVertex (objMesh, Vector3 (x, y, z));
			}
			*/
			else if (line[0] == 'f' && line[1] == ' ') // Indices
			{
				renkine::u32 p1, p2, p3;
				renkine::u32 t;
				sscanf (line, "f %i/%i/%i %i/%i/%i %i/%i/%i", &p1, &t, &t, &p2, &t, &t, &p3, &t, &t);
				MeshCreator::AddFace (objMesh, p1 - 1, p2 - 1, p3 - 1);
			}
		}

		return objMesh;
	}
}