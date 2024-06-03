#pragma once

namespace GLCore {
	class Renderer {
	private:
		Renderer() {}
		~Renderer() {}
	public:
		static Renderer& getInstance() {
			static Renderer instance;
			return instance;
		}

		Renderer(const Renderer& renderer) = delete;
		Renderer& operator=(const Renderer&) = delete;

		void Clear();
		//Draw(const IndexBuffer& indexBuffer, const VertexArray& vertexArray, const Shader& shader) const
	};
}