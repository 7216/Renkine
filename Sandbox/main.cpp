#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Renkine/Renkine.h>
#include <Renkine/math.h>
#include <Renkine/Graphics/shader.h>
#include <Renkine/Input/input.h>

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
	
	renkine::Input::Initialize ();
	glfwSetKeyCallback (window, renkine::Input::Key_callback);
	glfwSetMouseButtonCallback (window, renkine::Input::Button_callback);
	glfwSetCursorPosCallback (window, renkine::Input::Cursor_callback);


	renkine::Matrix4 P_Matrix = renkine::Matrix4 (1.0f);
	P_Matrix = P_Matrix.Perspective (120.0f, 16.0f / 9.0f, 0.01f, 150.0f);
	
	renkine::Matrix4 MV_Matrix = renkine::Matrix4 (1.0f);
	
	

	renkine::Mesh2D *mesh = renkine::MeshCreator2D::CreateQuadMesh ({1.0f, 1.0f});
	renkine::Renderable2D *renderable = renkine::Renderer2D::CreateRenderable (mesh);

	renkine::Shader shader = renkine::Shader ("test.vert", "test.frag");

	float z = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		renkine::Graphics::Clear (renkine::RGB (255, 0, 255));

		if (renkine::Input::IsKeyDown (GLFW_KEY_S))
			z -= 0.016f * 5;
		if (renkine::Input::IsKeyDown (GLFW_KEY_W))
			z += 0.016f * 5;

		MV_Matrix = MV_Matrix.Translate ({3.0f, 0.0f, z}) * MV_Matrix.Scale ({0.1f, 0.1f, 1.0f});


		renkine::Matrix4 MVP_Matrix = P_Matrix * MV_Matrix;

		shader.SetUniformMatrix4 ("MVP_Matrix", MVP_Matrix);
		shader.Enable ();

		
		renkine::Renderer2D::Render (renderable, {0.f, 0.f}, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
