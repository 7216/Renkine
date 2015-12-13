#include "input.h"

namespace renkine
{		
	bool Input::Keys[RENKINE_DEFINES_MAX_KEYS];
	bool Input::Buttons[RENKINE_DEFINES_MAX_BUTTONS];

	Vector2 Input::Mouse;

	void Input::Initialize ()
	{
		for (int i = 0; i < RENKINE_DEFINES_MAX_KEYS; i++)
		{
			Input::Keys[i] = false;
		}
		for (int i = 0; i < RENKINE_DEFINES_MAX_BUTTONS; i++)
		{
			Input::Buttons[i] = false;
		}
	}

	void Input::Key_callback (GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		Input::Keys[key] = action != GLFW_RELEASE;
	}

	void Input::Button_callback (GLFWwindow *window, int key, int action, int mods)
	{
		Input::Buttons[key] = action != GLFW_RELEASE;
	}

	void Input::Cursor_callback (GLFWwindow *window, double x, double y)
	{
		Input::Mouse.x = x;
		Input::Mouse.y = y;
	}

	bool Input::IsKeyDown (unsigned int key)
	{
		if (key >= RENKINE_DEFINES_MAX_KEYS) // TODO: Log it yo
			return false;
		return Input::Keys[key];
	}

	bool Input::IsButtonDown (unsigned int button)
	{
		if (button >= RENKINE_DEFINES_MAX_BUTTONS) // TODO: Log it yo
			return false;

		return Input::Buttons[button];
	}

}

