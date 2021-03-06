#include "renderer.h"
#include <GL/glew.h>
#include <stdlib.h>

namespace renkine
{
	Renderable *renkine::Renderer::CreateRenderable (Mesh *mesh, Shader *shader)
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
		renderable->shader = shader;


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

	void renkine::Renderer::Render (Camera &camera, Renderable *renderable, Vector3 position, Vector3 rotation, Vector3 skew)
	{
		renderable->shader->Enable ();
		renderable->shader->SetUniformMatrix4 ("ProjectionMatrix", camera.projection);
		renderable->shader->SetUniformMatrix4 ("ModelViewMatrix", camera.model_view);

		renkine::Matrix4 mvp;
		mvp = renkine::Matrix4::Translate (position) * renkine::Matrix4::Rotate ({1.0f, 0.0f, 0.0f}, rotation.x) * renkine::Matrix4::Rotate ({0.0f, 1.0f, 0.0f}, rotation.y) * renkine::Matrix4::Rotate ({0.0f, 0.0f, 1.0f}, rotation.z) * renkine::Matrix4::Skew (skew);
		mvp = camera.projection * camera.model_view * mvp;
		renderable->shader->SetUniformMatrix4 ("MVP", mvp);

		glBindVertexArray (renderable->vao);
		glBindBuffer (GL_ARRAY_BUFFER, renderable->vbo);
		glEnableVertexAttribArray (0);
		glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (renkine::Vector3), NULL);
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, renderable->ebo);
		glDrawElements (GL_TRIANGLES, renderable->mesh->index_count, GL_UNSIGNED_INT, NULL);
		renderable->shader->Disable ();
	}
}
