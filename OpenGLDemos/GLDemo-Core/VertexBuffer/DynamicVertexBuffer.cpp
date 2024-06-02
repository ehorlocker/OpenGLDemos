#include "DynamicVertexBuffer.h"

namespace GLCore {
	DynamicVertexBuffer::DynamicVertexBuffer(unsigned int size)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW);
	}

	void DynamicVertexBuffer::UpdateData(const void* data, unsigned int size, unsigned int offset)
	{
		Bind();
		glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	}
}