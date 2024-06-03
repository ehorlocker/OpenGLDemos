#include "VertexBuffer.h"
#include "Log.h"

namespace GLCore {
	VertexBuffer::VertexBuffer() {
		glGenBuffers(1, &m_RendererID);
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &m_RendererID);
	}

	void VertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
	}

	void VertexBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}