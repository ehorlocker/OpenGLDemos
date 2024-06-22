#include "Shader.h"

namespace GLCore {
	Shader::Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath)
		: m_VertexSource(ParseShader(vertexFilepath)), m_FragmentSource(ParseShader(fragmentFilepath)) {

	}

	Shader::~Shader() {

	}

	void Shader::Bind() const {

	}

	void Shader::Unbind() const {

	}

	std::string Shader::ParseShader(const std::string& filepath) {
		std::ifstream stream(filepath);
		std::string line;
		std::stringstream ss;
		while (getline(stream, line)) {
			ss << line << '\n'
		}
		return ss;
	}
}