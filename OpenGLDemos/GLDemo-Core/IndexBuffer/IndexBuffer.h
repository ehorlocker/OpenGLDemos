#pragma once

namespace GLCore {
	class IndexBuffer {
	private:
		unsigned int m_RendererID;
	public:
		IndexBuffer();
		virtual ~IndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual void UpdateData(unsigned int* data, unsigned int size, unsigned int offset) = 0;
	};
}