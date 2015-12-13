#include "Shader.h"

namespace renkine
{

	Shader::Shader(const char* vertexPath, const char* fragPath)
		: _VertexPath(vertexPath), _FragmentPath(fragPath)
	{
		_ShaderID = load();
	}
	Shader::~Shader()
	{
		glDeleteProgram(_ShaderID);
	}
	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		FILE *vertex_shader_file = NULL, *fragment_shader_file = NULL;
		vertex_shader_file = fopen (_VertexPath, "r");
		fragment_shader_file = fopen (_FragmentPath, "r");

		if (vertex_shader_file != NULL)
		{
			fseek (vertex_shader_file, 0, SEEK_END);
			int size = ftell (vertex_shader_file);
			fseek (vertex_shader_file, 0, SEEK_SET);
			char* vertexSource = NULL;
			vertexSource = (char *) malloc (size + 1);
			memset (vertexSource, '\0', size + 1);
			fread ((void *) vertexSource, size, 1, vertex_shader_file);
			
				

			glShaderSource(vertex, 1, &vertexSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);

				std::cout << "Failiure to compile vertex shader." << std::endl << &error[0] << std::endl;

				glDeleteShader(vertex);

				return 0;
			}

			free ((void *) vertexSource);
			fclose (vertex_shader_file);
		}

		if (fragment_shader_file != NULL)
		{
			fseek (fragment_shader_file, 0, SEEK_END);
			int size = ftell (fragment_shader_file);

			fseek (fragment_shader_file, 0, SEEK_SET);
			char* fragmentSource = NULL;
			fragmentSource = (char *) malloc (size + 1);
			memset (fragmentSource, '\0', size + 1);

			fread ((void *) fragmentSource, size, 1, fragment_shader_file);
			glShaderSource(fragment, 1, &fragmentSource, NULL);
			glCompileShader(fragment);

			GLint result = 0;

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);

				std::cout << "Failiure to compile fragment shader." << std::endl << &error[0] << std::endl;

				glDeleteShader(fragment);

				return 0;
			}

			free ((void *)fragmentSource);
			fclose (fragment_shader_file);
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	GLint Shader::GetUniformLocation(const GLchar *name)
	{
		return glGetUniformLocation(_ShaderID, name);
	}

	void Shader::SetUniformMatrix1f(const GLchar *name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}
	void Shader::SetUniformMatrix1i(const GLchar *name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}
	void Shader::SetUniformMatrix2f(const GLchar *name, const renkine::Vector2& vector)
	{
		glUniform2f(GetUniformLocation(name), vector.x, vector.y);
	}
	/*void Shader::SetUniformMatrix3f(const GLchar *name, const DMath::Vector3& vector)
	{
		glUniform3f(GetUniformLocation(name), vector._x, vector._y, vector._z);
	}*/
	void Shader::SetUniformMatrix4f(const GLchar *name, const renkine::Vector4& vector)
	{
		glUniform4f(GetUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}
	void Shader::SetUniformMatrix4(const GLchar *name, const renkine::Matrix4& matrix)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}

	void Shader::Enable() const
	{
		glUseProgram(_ShaderID);
	}
	void Shader::Disable() const
	{
		glUseProgram(0);
	}
}
