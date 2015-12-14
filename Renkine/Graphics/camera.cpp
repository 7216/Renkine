#include <Renkine/Graphics/camera.h>

namespace renkine
{
	Camera::Camera ()
	{
		this->projection.Identity ();
		this->model_view.Identity ();
	}
}
