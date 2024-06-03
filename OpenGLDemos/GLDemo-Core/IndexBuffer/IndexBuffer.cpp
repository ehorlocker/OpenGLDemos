#include "IndexBuffer.h"
#include "glad/glad.h"

namespace GLCore {
	IndexBuffer::IndexBuffer() {
		glGenBuffers(1, &m_RendererID);
	}

	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &m_RendererID);
	}

	void IndexBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	}

	void IndexBuffer::Unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}

