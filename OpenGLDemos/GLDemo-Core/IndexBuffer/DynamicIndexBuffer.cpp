#include "DynamicIndexBuffer.h"
#include "glad/glad.h"
#include "Log.h"

namespace GLCore {
	DynamicIndexBuffer::DynamicIndexBuffer(unsigned int size) 
		: m_Size(size) {
		Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
	}

	void DynamicIndexBuffer::UpdateData(unsigned int* data, unsigned int size, unsigned int offset) {
		if (size <= m_Size) {
			Bind();
			glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, size, data);
		}
		else {
			LOG_ERROR("Data size too large for dynamic index buffer");
		}
	}
}
