#include <Renkine/Graphics/camera.h>

namespace renkine
{
	Camera::Camera ()
	{
		this->projection.Identity ();
		this->model_view.Identity ();
	}

	void Camera::SetProjection (Matrix4 projection)
	{
		this->projection = projection;
	}

	void Camera::SetPosition (Vector3 position)
	{
		model_view.Translate (position);
	}
}
