#include "ClearColor.h"
#include "glad/glad.h"

namespace scene {
	ClearColor::ClearColor()
		: m_Color{ 0.3f, 0.4f, 1.0f, 1.0f } {

	}

	void ClearColor::OnRender() {
		glClearColor(m_Color[0], m_Color[1], m_Color[2], m_Color[3]);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void ClearColor::OnImGuiRender() {

	}
}