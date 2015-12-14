#version 440

layout (location = 0) in vec4 Vertex;
layout (location = 1) in vec4 UVCoord;
uniform mat4 ProjectionMatrix;
uniform mat4 ModelViewMatrix;
uniform mat4 Transform;

void main ()
{
	gl_Position = ProjectionMatrix * (ModelViewMatrix * Transform) * Vertex;
}
