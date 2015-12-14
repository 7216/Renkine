#ifndef RENKINE_GRAPHICS_RENDERER_H
#define RENKINE_GRAPHICS_RENDERER_H

#include <Renkine/Types/types.h>
#include <Renkine/Math/vector2.h>
#include <Renkine/Types/graphics_types.h>
#include <Renkine/Graphics/camera.h>

namespace renkine
{
	class Renderer
	{
	public:
		static Renderable *CreateRenderable (Mesh *mesh, const char* vertex_shader, const char *fragment_shader);
		static void Render (Renderable *renderable, Vector3 position, Vector3 rotation);
	};
}

#endif // RENKINE_GRAPHICS_RENDERER_H
