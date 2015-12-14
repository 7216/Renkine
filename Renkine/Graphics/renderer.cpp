#include "renderer.h"
#include <GL/glew.h>
#include <stdlib.h>

namespace renkine
{
	Renderable *renkine::Renderer::CreateRenderable (Mesh *mesh, const char* vertex_shader, const char *fragment_shader)
	{
		if (mesh == NULL)
		{
			return NULL;
		}


		Renderable *renderable = NULL;
		renderable = (Renderable *) malloc (sizeof (Renderable));
		if (renderable == NULL)
		{
			return NULL;
		}

		renderable->vao = 0;
		renderable->vbo = 0;
		renderable->ebo = 0;
		renderable->mesh = mesh;
		renderable->shader = Shader (vertex_shader, fragment_shader);


		glGenVertexArrays (1, &renderable->vao);
		glBindVertexArray (renderable->vao);

		glGenBuffers (1, &renderable->vbo); 
		glBindBuffer (GL_ARRAY_BUFFER, renderable->vbo);
		glBufferData (GL_ARRAY_BUFFER, sizeof (Vector3) * renderable->mesh->vertex_count, renderable->mesh->vertices, GL_STATIC_DRAW);

		glGenBuffers (1, &renderable->ebo);
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, renderable->ebo);
		glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (renkine::u32) * renderable->mesh->index_count, renderable->mesh->indices, GL_STATIC_DRAW);

		return renderable;
	}

	void renkine::Renderer::Render (Renderable *renderable, Vector3 position, Vector3 rotation)
	{
				
	}
}
