#ifndef RENKINE_GRAPHICS_CAMERA_H
#define RENKINE_GRAPHICS_CAMERA_H

#include <Renkine/Math/matrix4.h>

namespace renkine
{
	class Camera
	{
	public:
		Camera ();

		Matrix4 projection;
		Matrix4 model_view;
	};
}

#endif // RENKINE_GRAPHICS_CAMERA_H
