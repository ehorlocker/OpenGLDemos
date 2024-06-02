#include "VertexBuffer.h"

namespace GLCore {
	class StaticVertexBuffer : public VertexBuffer {
	public:
		StaticVertexBuffer(const void* data, unsigned int size);

		virtual void UpdateData(const void* data, unsigned int size, unsigned int offset = 0) override;
	};
}