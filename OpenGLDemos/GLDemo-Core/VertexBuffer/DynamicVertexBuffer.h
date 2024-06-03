#pragma once

#include "VertexBuffer.h"

namespace GLCore {
	class DynamicVertexBuffer : public VertexBuffer {
	private:
		unsigned int m_Size;
	public:
		DynamicVertexBuffer(unsigned int size);

		virtual void UpdateData(const void* data, unsigned int size, unsigned int offset = 0) override;
	};
}