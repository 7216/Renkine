#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Renkine/Renkine.h>
#include <Renkine/math.h>
#include <Renkine/Graphics/shader.h>


#include <iostream>

int main()
{
	if (!glfwInit())
	{
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(1280, 720, "Renkine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);
	glewInit ();

	int width = 0, height = 0;
	glfwGetMonitorPhysicalSize (glfwGetPrimaryMonitor (), &width, &height);
	glfwSetWindowPos (window, width / 2, height / 2);

	

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

	float fov = 120.0f;
	float q = 1.0f / tan((fov * .5f) * (3.14f / 180.0f));
	float a = q / (1280.0f / 720.0f);
	float b = (0.01 + 1500) / (0.01 - 1500);
	float c = (2.0f * 0.01 * 1500) / (0.01 - 1500);

	matrix[0 + 0 * 4] = a;
	matrix[1 + 1 * 4] = q;
	matrix[2 + 2 * 4] = b;
	matrix[3 + 2 * 4] = -1.f;
	matrix[2 + 3 * 4] = c;

	renkine::Matrix4 MVP_Matrix = renkine::Matrix4 (1.0f);
	MVP_Matrix.elements [0 + 0 * 4] = a;
	MVP_Matrix.elements [1 + 1 * 4] = q;
	MVP_Matrix.elements [2 + 2 * 4] = b;
	MVP_Matrix.elements [3 + 2 * 4] = -1.f;
	MVP_Matrix.elements [2 + 3 * 4] = c;

	renkine::Graphics::SetProjectionMatrix (MVP_Matrix);

	renkine::Mesh2D *mesh = renkine::MeshCreator2D::CreateQuadMesh ({1.0f, 1.0f});
	renkine::Renderable2D *renderable = renkine::Renderer2D::CreateRenderable (mesh);

	renkine::Shader shader = renkine::Shader ("test.vert", "test.frag");

	while (!glfwWindowShouldClose(window))
	{
		renkine::Graphics::Clear (renkine::RGB (255, 0, 255));

		shader.SetUniformMatrix4 ("MVP_Matrix", MVP_Matrix);
		shader.Enable ();
		renkine::Renderer2D::Render (renderable, {0.f, 0.f}, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
