#pragma once

#include <vector>
#include "glad/glad.h"


namespace GLCore {
	struct VertexBufferElement {
		unsigned int type;
		unsigned int count;
		unsigned int normalized;

		VertexBufferElement(unsigned int t, unsigned int c, unsigned char n)
			: type(t), count(c), normalized(n) {

		}

		static unsigned int GetSizeOfType(unsigned int type) {
			switch (type) {
				case GL_UNSIGNED_INT:
					return 4;
				case GL_FLOAT:
					return 4;
				case GL_UNSIGNED_BYTE:
					return 1;
			}
		}
	};

	class VertexBufferLayout {
	private:
		std::vector<VertexBufferElement> m_Elements;
		unsigned int m_Stride;
	public:
		VertexBufferLayout()
			: m_Stride(0) {};

		template<typename T>
		void Push(unsigned int count);

		template<>
		void Push<float>(unsigned int count) {
			m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
			m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
		}

		template<>
		void Push<unsigned int>(unsigned int count) {
			m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
			m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count;
		}

		template<>
		void Push<unsigned char>(unsigned int count) {
			m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
			m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
		}

		inline std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
		inline unsigned int GetStride() const { return m_Stride; }
	};
}
