#pragma once

#include "IndexBuffer.h"

namespace GLCore {
	class DynamicIndexBuffer : public IndexBuffer {
	private:
		unsigned int m_Size;
	public:
		DynamicIndexBuffer(unsigned int size);

		void UpdateData(unsigned int* data, unsigned int size, unsigned int offset);
	};
}