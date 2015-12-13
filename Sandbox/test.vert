#version 330

layout (location = 0) in vec4 Vertex;

void main ()
{
	gl_Position = Vertex;
}
