#include "StaticVertexBuffer.h"
#include "Log.h"

namespace GLCore {
	StaticVertexBuffer::StaticVertexBuffer(const void* data, unsigned int size) {
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void StaticVertexBuffer::UpdateData(const void* data, unsigned int size, unsigned int offset) {
		LOG_ERROR("Static vertex buffer object cannot update data");
	}
}