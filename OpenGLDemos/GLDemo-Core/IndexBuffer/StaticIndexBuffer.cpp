#include "StaticIndexBuffer.h"
#include "glad/glad.h"
#include "Log.h"

namespace GLCore {
	StaticIndexBuffer::StaticIndexBuffer(unsigned int* data, unsigned int count)
		: m_Count(count) {
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
	}

	void StaticIndexBuffer::UpdateData(unsigned int* data, unsigned int size, unsigned int offset) {
		LOG_ERROR("Static index buffer object cannot update data");
	}
}

