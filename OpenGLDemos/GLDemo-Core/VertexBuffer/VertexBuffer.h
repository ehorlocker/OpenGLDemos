#pragma once
#include "glad/glad.h"

namespace GLCore {
	class VertexBuffer {
	protected:
		unsigned int m_RendererID;

		VertexBuffer();

	public:
		virtual ~VertexBuffer();

		virtual void Bind();
		virtual void Unbind();

		virtual void UpdateData(const void* data, unsigned int size, unsigned int offset = 0) = 0;
	};
}