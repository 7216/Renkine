#ifndef RENKINE_GRAPHICS_SHADER_H
#define RENKINE_GRAPHICS_SHADER_H

#include <iostream>
#include <vector>
#include <GL\glew.h>
#include <Renkine/Math/vector2.h>
#include <Renkine/Math/matrix4.h>

namespace renkine
{
	class Shader
	{
	private:
		GLuint _ShaderID;
		const char* _VertexPath, *_FragmentPath;

		GLint GetUniformLocation(const GLchar *name);

		GLuint load();
	public:
		Shader(const char* vertexPath, const char* fragPath);
		~Shader();

			

		void SetUniformMatrix1f(const GLchar *name, float value);
		void SetUniformMatrix1i(const GLchar *name, int value);
		void SetUniformMatrix2f(const GLchar *name, const renkine::Vector2& vector);
		//void SetUniformMatrix3f(const GLchar *name, const renkine::Vector3& vector);
		void SetUniformMatrix4f(const GLchar *name, const renkine::Vector4& vector);
		void SetUniformMatrix4(const GLchar *name, const renkine::Matrix4& matrix);

		void Enable() const;
		void Disable() const;
	};
}

#endif //  RENKINE_GRAPHICS_SHADER_H
