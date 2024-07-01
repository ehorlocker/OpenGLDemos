#include "Renderer.h"
#include "glad/glad.h"

namespace GLCore {
	void Renderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::DrawStatic(const VertexArray& va, const StaticIndexBuffer& ib, const Shader& shader) const {
		shader.Bind();
		va.Bind();
		ib.Bind();

		glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::DrawDynamic(const VertexArray& va, const DynamicIndexBuffer& ib, const unsigned int ibCount, const Shader& shader) const {
		shader.Bind();
		va.Bind();
		ib.Bind();

		glDrawElements(GL_TRIANGLES, ibCount, GL_UNSIGNED_INT, nullptr);
	}
}