#include "BatchRendering.h"

namespace scene {
	BatchRendering::BatchRendering()
		: m_QuadCount(0), m_DrawCalls(1) {
		float positions[] = {
			-50.0f, -50.0f, 0.0f, 0.0f, // 0
			 50.0f, -50.0f, 1.0f, 0.0f, // 1
			 50.0f,  50.0f, 1.0f, 1.0f, // 2
			-50.0f,  50.0f, 0.0f, 1.0f  // 3
		};

		unsigned int indicies[] = {
			0, 1, 2,
			2, 3, 0
		};

		m_VertexBuffer = 
			std::make_unique<GLCore::DynamicVertexBuffer>(1024);

		m_IndexBuffer =
			std::make_unique<GLCore::DynamicIndexBuffer>(1024);

		m_VertexBufferLayout = 
			std::make_unique<GLCore::VertexBufferLayout>();
		
		m_VertexArray =
			std::make_unique<GLCore::VertexArray>();

		m_Renderer =
			std::make_unique<GLCore::Renderer>();

		m_VertexBufferLayout->Push<float>(2);
		m_VertexBufferLayout->Push<float>(2);
		m_VertexArray->AddBuffer(*m_VertexBuffer, *m_VertexBufferLayout);

		m_VertexBuffer->UpdateData(positions, 4 * 4 * sizeof(float), 0);
		m_IndexBuffer->UpdateData(indicies, 2 * 3 * sizeof(unsigned int), 0);

		/*
        glm::mat4 mvp = m_Projection * m_Model * m_View;

        m_Shader = new Shader("res/shaders/basic.shader");
        m_Shader->Bind();
        m_Shader->SetUniformMat4f("u_MVP", mvp);
		*/
	}

	BatchRendering::~BatchRendering() {

	}

	void BatchRendering::OnRender() {
		m_Renderer->Clear();
	}

	void BatchRendering::OnImGuiRender() {
	}
}