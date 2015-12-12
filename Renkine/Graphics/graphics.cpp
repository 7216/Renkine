#include "graphics.h"
#include <GL/glew.h>

namespace renkine
{
	void Graphics::SetProjectionMatrix (float *matrix)
	{
		glMatrixMode (GL_PROJECTION);
		glLoadIdentity ();
		glLoadMatrixf (matrix);
		glMatrixMode (GL_MODELVIEW);
	}

	void Graphics::Clear (RGB color)
	{
		glClearColor ((float)color.r / 255.0f, (float)color.g / 255.0f, (float)color.b / 255.0f, 1.0f);
		glClear (GL_COLOR_BUFFER_BIT);
	}

	void Graphics::Clear (RGBf color)
	{
		glClearColor (color.r, color.g, color.b, 1.0f);
		glClear (GL_COLOR_BUFFER_BIT);
	}
}
