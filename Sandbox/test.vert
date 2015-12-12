#version 330

void main ()
{
	gl_Position = gl_ProjectionMatrix * gl_Vertex;
}
