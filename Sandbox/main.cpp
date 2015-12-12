#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Renkine/Renkine.h>
#include <Renkine/math.h>
#include <Renkine/Graphics/shader.h>


#include <iostream>

int main()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Renkine", NULL, NULL);

	int width = 0, height = 0;
	glfwGetMonitorPhysicalSize (glfwGetPrimaryMonitor (), &width, &height);
	glfwSetWindowPos (window, width / 2, height / 2);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewInit ();

	float left = 0.0f;
	float right = 1280.0f;
	float top = 0.0f;
	float bottom = 720.0f;
	float zfar = 1.0f;
	float znear = -1.0f;

	float matrix [16] = {1.0f, 0.0f, 0.0f, 0.0f,
						 0.0f, 1.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, 1.0f, 0.0f,
						 0.0f, 0.0f, 0.0f, 1.0f};

	float fov = 90.0f;
	float q = 1.0f / tan((fov * .5f) * (3.14f / 180.0f));
	float a = q / (1280.0f / 720.0f);
	float b = (0.01 + 1500) / (0.01 - 1500);
	float c = (2.0f * 0.01 * 1500) / (0.01 - 1500);

	matrix[0 + 0 * 4] = a;
	matrix[1 + 1 * 4] = q;
	matrix[2 + 2 * 4] = b;
	matrix[3 + 2 * 4] = -1.f;
	matrix[2 + 3 * 4] = c;


	renkine::Graphics::SetProjectionMatrix (matrix);

	renkine::Mesh2D *mesh = renkine::MeshCreator2D::CreateQuadMesh ({1.0f, 1.0f});
	renkine::Renderable2D *renderable = renkine::Renderer2D::CreateRenderable (mesh);

	renkine::Shader shader = renkine::Shader ("test.vert", "test.frag");

	/*renkine::Vector2 a = renkine::Vector2(5.0f, 5.0f);
	renkine::Vector2 b = renkine::Vector2(5.0f, 5.0f);
	renkine::Vector2 c = a*b;
	printf("%f, %f", c.x, c.y);
	*/
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		renkine::Graphics::Clear (renkine::RGB (255, 0, 255));

		shader.enable ();
		renkine::Renderer2D::Render (renderable, {0.f, 0.f}, 0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
