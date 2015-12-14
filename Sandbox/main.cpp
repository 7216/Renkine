#include <Renkine/Renkine.h>



void Display ()
{
	renkine::Graphics::Clear (renkine::RGB (0, 0, 0));
}

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

	int width = 0, height = 0;
	glfwGetMonitorPhysicalSize (glfwGetPrimaryMonitor (), &width, &height);
	glfwSetWindowPos (window, width / 2, height / 2);

	while (!glfwWindowShouldClose(window))
	{
		Display ();	

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
