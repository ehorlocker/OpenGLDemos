#include "Shader.h"
#include "glad/glad.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Log.h"

namespace GLCore {
	Shader::Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath) {
		std::string vertexSource = ParseShader(vertexFilepath);
		std::string fragmentSource = ParseShader(fragmentFilepath);
		std::cout << vertexSource << std::endl << fragmentSource;
		unsigned int program = glCreateProgram();
		unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
		unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);
		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		m_RendererID = program;
	}

	Shader::~Shader() {
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind() const {
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const {
		glUseProgram(0);
	}

	void Shader::SetUniform1f(const std::string& name, float v0) {
		glUniform1f(GetUniformLocation(name), v0);
	}

	void Shader::SetUniform1i(const std::string& name, int v0) {
		glUniform1i(GetUniformLocation(name), v0);
	}

	void Shader::SetUniform1iv(const std::string& name, int* array, int count) {
		glUniform1iv(GetUniformLocation(name), count, array);
	}

	void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
		glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
	}

	void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix) {
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
	}

	std::string Shader::ParseShader(const std::string& filepath) {
		std::ifstream stream(filepath);
		std::string line;
		std::stringstream ss;
		while (getline(stream, line)) {
			ss << line << '\n';
			std::cout << line << std::endl;
		}
		return ss.str();
	}

	unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, NULL);
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			std::stringstream ss;
			ss << "Failed to compile "
				<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
				<< " shader!";
			LOG_ERROR("[OpenGL Debug HIGH] {0}", ss.str());
			LOG_ERROR("[OpenGL Debug HIGH] {0}", message);
			glDeleteShader(id);
			return 0;
		}

		return id;
	}

	int Shader::GetUniformLocation(const std::string& name) {
		auto uniformLocation = m_UniformLocationCache.find(name);
		if (uniformLocation != m_UniformLocationCache.end()) {
			return uniformLocation->second;
		}

		int location = glGetUniformLocation(m_RendererID, name.c_str());
		if (location == -1) {
			std::stringstream ss;
			ss << "Warning: uniform '" << name << "' doesn't exist.";
			LOG_ERROR("[OpenGL Debug HIGH] {0}", ss.str());
		}

		m_UniformLocationCache[name] = location;
		return location;
	}
}