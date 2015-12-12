#include "renderer.h"
#include <GL/glew.h>
#include <stdlib.h>

namespace renkine
{
	Renderable2D *renkine::Renderer2D::CreateRenderable (Mesh2D *mesh)
	{
		if (mesh == NULL)
		{
			return NULL;
		}


		Renderable2D *renderable = NULL;
		renderable = (Renderable2D *) malloc (sizeof (Renderable2D));
		if (renderable == NULL)
		{
			return NULL;
		}

		renderable->_vertex_buffer = 0;
		renderable->_uv_buffer = 0;
		renderable->_element_buffer = 0;
		glGenBuffers (1, &renderable->_vertex_buffer);
		glGenBuffers (1, &renderable->_uv_buffer);
		glGenBuffers (1, &renderable->_element_buffer);
		renderable->mesh = mesh;


		glBindBuffer (GL_ARRAY_BUFFER, renderable->_vertex_buffer);
		glBufferData (GL_ARRAY_BUFFER, (sizeof (Vector2) * renderable->mesh->vertex_count), renderable->mesh->vertices, GL_STATIC_DRAW);
		glBindBuffer (GL_ARRAY_BUFFER, 0);

		glBindBuffer (GL_ARRAY_BUFFER, renderable->_uv_buffer);
		glBufferData (GL_ARRAY_BUFFER, (sizeof (Vector2) * renderable->mesh->uv_coord_count), renderable->mesh->uv_coords, GL_STATIC_DRAW);
		glBindBuffer (GL_ARRAY_BUFFER, 0);

		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, renderable->_element_buffer);
		glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (Vector2) * renderable->mesh->index_count, renderable->mesh->indices, GL_STATIC_DRAW);
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);

		return renderable;
	}

	void renkine::Renderer2D::Render (Renderable2D *renderable, Vector2 position, float rotation)
	{
		glPushMatrix ();
			glTranslatef (position.x, position.y, 0.0f);
			glRotatef 	 (rotation, 0.0f, 0.0f, 1.0f);

			glEnableClientState (GL_VERTEX_ARRAY);
			glBindBuffer (GL_ARRAY_BUFFER, renderable->_vertex_buffer);
			glVertexPointer (2, GL_FLOAT, sizeof (Vector2), NULL);

			if (renderable->mesh->uv_coord_count != 0)
			{
				glEnableClientState (GL_TEXTURE_COORD_ARRAY);
				glBindBuffer (GL_TEXTURE_COORD_ARRAY, renderable->_uv_buffer);
				glTexCoordPointer (2, GL_FLOAT, sizeof (Vector2), NULL);
			}

			glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, renderable->_element_buffer);
			glDrawElements (GL_TRIANGLES, renderable->mesh->index_count, GL_UNSIGNED_INT, NULL);
			
			
			glDisableClientState (GL_VERTEX_ARRAY);
			glDisableClientState (GL_TEXTURE_COORD_ARRAY);

			glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindBuffer (GL_ARRAY_BUFFER, 0);
		glPopMatrix ();
	}
}
