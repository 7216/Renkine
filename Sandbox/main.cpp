#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Renkine/Renkine.h>


int main()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewInit ();
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glOrtho (0, 1280, 720, 0, -1, 1);
	glMatrixMode (GL_MODELVIEW);

	renkine::Mesh2D *mesh = renkine::MeshCreator2D::CreateQuadMesh ({256.0f, 128.0f});
	renkine::Renderable2D *renderable = renkine::Renderer2D::CreateRenderable (mesh);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
		glClear (GL_COLOR_BUFFER_BIT);

		renkine::Renderer2D::Render (renderable, {320.0f, 232.0f}, 0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
