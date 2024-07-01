#pragma once
#include "IndexBuffer.h"

namespace GLCore {
	class StaticIndexBuffer : public IndexBuffer {
	private:
		unsigned int m_Count;
	public:
		StaticIndexBuffer(unsigned int* data, unsigned int count);

		void UpdateData(unsigned int* data, unsigned int size, unsigned int offset);
		unsigned int GetCount() const;
	};
}