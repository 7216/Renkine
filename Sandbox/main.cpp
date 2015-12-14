#include <Renkine/Renkine.h>

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
	shader.Enable ();

	renkine::Matrix4 projection, modelview;
	projection.Perspective (90.0f, 16.0f / 9.0f, 0.01f, 1500.0f);
	modelview.Identity ();

	renkine::Vector3 camera_position = {0.0f, 0.0f, 5.0f};
	renkine::Vector3 position = {0.0f, 0.0f, -5.0f};
	float vertices[] = {
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	renkine::u32 indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	renkine::u32 vao, vbo, ebo;

	glGenVertexArrays (1, &vao);
	glBindVertexArray (vao);

	glGenBuffers (1, &vbo); 
	glBindBuffer (GL_ARRAY_BUFFER, vbo);
	glBufferData (GL_ARRAY_BUFFER, (sizeof (float) * 3) * 4, vertices, GL_STATIC_DRAW);

	glGenBuffers		(1, &ebo);
	glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData (GL_ELEMENT_ARRAY_BUFFER, (sizeof (renkine::u32) * 3) * 2, indices, GL_STATIC_DRAW);




	while (!glfwWindowShouldClose(window))
	{
		renkine::Graphics::Clear (renkine::RGB (0, 0, 0));

		shader.SetUniformMatrix4 ("ProjectionMatrix", projection);
		shader.SetUniformMatrix4 ("ModelViewMatrix", modelview);

		renkine::Matrix4 transform;
		transform.Identity ();
		transform.Translate (position);
		shader.SetUniformMatrix4 ("Transform", transform);
		
		glBindVertexArray (vao);
		glBindBuffer (GL_ARRAY_BUFFER, vbo);
		glEnableVertexAttribArray (0);
		glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (float) * 3, NULL);
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, ebo);
		glDrawElements (GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

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
	}

	glfwTerminate();
	return 0;
}
