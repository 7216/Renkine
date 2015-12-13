#version 440

layout (location = 0) in vec4 Vertex;
layout (location = 1) in vec4 UVCoord;
uniform mat4 MVP_Matrix;

void main ()
{
	gl_Position = MVP_Matrix * Vertex;
}
