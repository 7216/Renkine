#ifndef RENKINE_GRAPHICS_RENDERER_H
#define RENKINE_GRAPHICS_RENDERER_H

#include <Renkine/Types/types.h>
#include <Renkine/Math/vector2.h>
#include <Renkine/Types/graphics_types.h>

namespace renkine
{
	class Renderer2D
	{
	public:
		static Renderable2D *CreateRenderable (Mesh2D *mesh);
		static void Render (Renderable2D *renderable, Vector2 position, float rotation);
	};
}

#endif // RENKINE_GRAPHICS_RENDERER_H
