#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Renkine/Renkine.h>
#include <Renkine\math.h>

#include <iostream>

int main()
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	renkine::Vector2 a = renkine::Vector2(5.0f, 5.0f);
	renkine::Vector2 b = renkine::Vector2(5.0f, 5.0f);
	renkine::Vector2 c = a*b;
	printf("%f, %f", c.x, c.y);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
