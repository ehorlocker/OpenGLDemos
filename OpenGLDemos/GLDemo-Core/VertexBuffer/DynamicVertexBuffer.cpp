#include "DynamicVertexBuffer.h"
#include "Log.h"

namespace GLCore {
	DynamicVertexBuffer::DynamicVertexBuffer(unsigned int size)
		: m_Size(size) {
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW);
	}

	void DynamicVertexBuffer::UpdateData(const void* data, unsigned int size, unsigned int offset) {
		if (size <= m_Size) {
			Bind();
			glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
		}
		else {
			LOG_ERROR("Data size too large for dynamic vertex buffer");
		}
	}
}