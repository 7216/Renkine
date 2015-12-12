#ifndef RENKINE_GRAPHICS_SHADER_H
#define RENKINE_GRAPHICS_SHADER_H

#include <iostream>
#include <vector>
#include <GL\glew.h>

namespace renkine
{
	class Shader
	{
	private:
		GLuint _ShaderID;
		const char* _VertexPath, *_FragmentPath;

		GLint getUniformLocation(const GLchar *name);

		GLuint load();
	public:
		Shader(const char* vertexPath, const char* fragPath);
		~Shader();

			

		/*void setUniformMatrix1f(const GLchar *name, float value);
		void setUniformMatrix1i(const GLchar *name, int value);
		void setUniformMatrix2f(const GLchar *name, const DMath::Vector2& vector);
		void setUniformMatrix3f(const GLchar *name, const DMath::Vector3& vector);
		void setUniformMatrix4f(const GLchar *name, const DMath::Vector4& vector);
		void setUniformMatrix4(const GLchar *name, const DMath::Matrix4& matrix);*/

		void enable() const;
		void disable() const;
	};
}

#endif //  RENKINE_GRAPHICS_SHADER_H
