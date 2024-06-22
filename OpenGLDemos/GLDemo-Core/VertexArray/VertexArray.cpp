#include "VertexArray.h"
#include "glad/glad.h"
#include <vector>
#include "Log.h"

namespace GLCore {
	VertexArray::VertexArray() {
		glGenVertexArrays(1, &m_RendererID);
	}

	VertexArray::~VertexArray() {
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void VertexArray::Bind() const {
		glBindVertexArray(m_RendererID);
	}

	void VertexArray::Unbind() const {
		glBindVertexArray(0);
	}

	void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout) {
		Bind();
		vertexBuffer.Bind();
		const std::vector<VertexBufferElement> elements = layout.GetElements();
		unsigned int offset = 0;
		for (int i = 0; i < elements.size(); i++) {
			const VertexBufferElement& element = elements[i];
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i,
				element.count,
				element.type,
				element.normalized,
				layout.GetStride(),
				(const void*) offset);
			offset += VertexBufferElement::GetSizeOfType(element.type) * element.count;
		}
	}
}