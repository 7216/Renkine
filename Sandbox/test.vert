#version 440

layout (location = 0) in vec4 Vertex;
uniform mat4 MVP_Matrix;

void main ()
{
	gl_Position = Vertex * MVP_Matrix;
}
