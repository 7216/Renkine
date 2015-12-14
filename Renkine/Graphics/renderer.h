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
		static Renderable *CreateRenderable (Mesh *mesh, Shader *shader);
		static void Render (Camera &camera, Renderable *renderable, Vector3 position, Vector3 rotation, Vector3 skew);
	};
}

#endif // RENKINE_GRAPHICS_RENDERER_H
