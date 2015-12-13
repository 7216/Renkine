#version 440

layout (location = 0) in vec2 Vertex;
layout (location = 1) in vec4 UVCoord;
uniform mat4 MVP_Matrix;

void main ()
{
	gl_Position = MVP_Matrix * vec4(Vertex, 0.0, 1.0);
}
