#pragma once
#include <string>

namespace GLCore {
	class Shader {
	private:
		std::string m_VertexSource;
		std::string m_FragmentSource;
		unsigned int m_RendererID;
	public:
		Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		std::string ParseShader(const std::string& filepath);
	};
}