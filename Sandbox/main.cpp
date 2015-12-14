#include <Renkine/Renkine.h>
#include <Windows.h>

int main (int argc, char **argv)
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
	renkine::Input::Initialize ();

	int width = 0, height = 0;
	glfwGetMonitorPhysicalSize (glfwGetPrimaryMonitor (), &width, &height);
	glfwSetWindowPos (window, width / 2, height / 2);
	glfwSetKeyCallback (window, renkine::Input::Key_callback);

	renkine::Shader shader = renkine::Shader ("test.vert", "test.frag");


	renkine::Vector3 camera_position = {0.0f, 0.0f, 0.0f};
	renkine::Vector3 position = {0.0f, 0.0f, -5.0f};


	renkine::Camera camera;
	camera.model_view = renkine::Matrix4::Translate		(camera_position);
	camera.projection = renkine::Matrix4::Perspective	(90.0f, 16.0f / 9.0f, 0.01f, 1500.0f);
	
	renkine::Mesh *mesh = renkine::ModelLoader::LoadOBJ("man.qqq"); //::CreateQuadMesh ({1.0f, 1.0f});
	renkine::Renderable *renderable = renkine::Renderer::CreateRenderable (mesh, &shader);



	float a = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		a += 0.016f * 1.0f;
		renkine::Graphics::Clear (renkine::RGBf (0.0f, 0.0f, 0.0f));
		renkine::Renderer::Render (camera, renderable, position, {}, {sinf (a), cos (a), 0.0f});

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (renkine::Input::IsKeyDown (GLFW_KEY_A))
		{
			position.x -= 0.016f * 5.0f;
		}

		if (renkine::Input::IsKeyDown (GLFW_KEY_D))
		{
			position.x += 0.016f * 5.0f;
		}


		if (renkine::Input::IsKeyDown (GLFW_KEY_W))
		{
			position.y += 0.016f * 5.0f;
		}

		if (renkine::Input::IsKeyDown (GLFW_KEY_S))
		{
			position.y -= 0.016f * 5.0f;
		}


		if (renkine::Input::IsKeyDown (GLFW_KEY_LEFT_CONTROL))
		{
			position.z += 0.016f * 5.0f;
		}

		if (renkine::Input::IsKeyDown (GLFW_KEY_LEFT_SHIFT))
		{
			position.z -= 0.016f * 5.0f;
		}

		Sleep (16);
	}

	glfwTerminate();
	return 0;
}
