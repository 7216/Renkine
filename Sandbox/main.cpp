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


	renkine::Matrix4 MVP_Matrix = renkine::Matrix4 (1.0f);
	MVP_Matrix.Perspective (90.0f, 16.0f / 9.0f, 0.01f, 150.0f);

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
