#ifndef RENKINE_TYPES_INPUT_H
#define RENKINE_TYPES_INPUT_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <Renkine\math.h>

#define RENKINE_DEFINES_MAX_KEYS 1024
#define RENKINE_DEFINES_MAX_BUTTONS 32

namespace renkine
{
	class Input
	{
	private:
		static bool Keys[RENKINE_DEFINES_MAX_KEYS];
		static bool Buttons[RENKINE_DEFINES_MAX_BUTTONS];

	public:
		static Vector2 Mouse;

		static void Initialize ();

		static void key_callback (GLFWwindow *window, int key, int scancode, int action, int mods);
		static void button_callback (GLFWwindow *window, int key, int action, int mods);
		static void cursor_callback (GLFWwindow *window, double x, double y);

		static bool isKeyDown (unsigned int keycode);
		static bool isButtonDown (unsigned int keycode);

	};
}

#endif // RENKINE_TYPES_INPUT_H