#pragma once
#include <string>
#pragma once
#include "glm/glm.hpp"

namespace GLCore {
	class Shader {
	private:
		unsigned int m_RendererID;
		std::unordered_map<std::string, int> m_UniformLocationCache;
	public:
		Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetUniform1f(const std::string& name, float v0);
		void SetUniform1i(const std::string& name, int v0);
		void SetUniform1iv(const std::string& name, int* array, int count);
		void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ParseShader(const std::string& filepath);
		unsigned int CompileShader(unsigned int type, const std::string& source);

		int GetUniformLocation(const std::string& name);
	};
}