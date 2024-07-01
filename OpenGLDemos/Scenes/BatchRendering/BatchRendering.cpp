#include "BatchRendering.h"
#include "imgui.h"
#include "glm/gtc/matrix_transform.hpp"

namespace scene {
	BatchRendering::BatchRendering()
		: m_QuadCount(0), m_DrawCalls(1), 
		m_Projection(glm::ortho(0.0f, 1920.0f, 0.0f, 1080.0f, -1.0f, 1.0f)),
		m_View(glm::mat4(1.0f)), m_Model(glm::mat4(1.0f)) {
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

		m_Shader = 
			std::make_unique<GLCore::Shader>("res/batchrendering.vertex.glsl", "res/batchrendering.fragment.glsl");

		m_VertexBufferLayout->Push<float>(2);
		m_VertexBufferLayout->Push<float>(2);
		m_VertexArray->AddBuffer(*m_VertexBuffer, *m_VertexBufferLayout);

		m_VertexBuffer->UpdateData(positions, 4 * 4 * sizeof(float), 0);
		m_IndexBuffer->UpdateData(indicies, 2 * 3 * sizeof(unsigned int), 0);
	}

	BatchRendering::~BatchRendering() {

	}

	void BatchRendering::OnRender() {
		m_Renderer->Clear();
		m_Model = glm::translate(glm::mat4(1.0f), glm::vec3(850, 490, 0));
		glm::mat4 mvp = m_Projection * m_Model * m_View;
		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_MVP", mvp);
		m_Shader->SetUniform4f("u_Color", 1.0, 1.0, 1.0, 1.0);
		m_Renderer->DrawDynamic(*m_VertexArray, *m_IndexBuffer, 6, *m_Shader);
	}

	void BatchRendering::OnImGuiRender() {
		ImGui::Text("Number of squares");
		ImGui::SliderInt("##quad", &m_QuadCount, 0, 100);
		ImGui::Text("Number of draw calls");
		ImGui::SliderInt("##draw", &m_DrawCalls, 1, 100);
	}
}