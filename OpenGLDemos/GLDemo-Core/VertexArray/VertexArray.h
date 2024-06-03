#pragma once

#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

namespace GLCore {
	class VertexArray {
	private:
		unsigned int m_RendererID;

	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;

		void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);
	};
}