#include "Squares.h"
#include "imgui.h"
#include "glm/gtc/matrix_transform.hpp"

namespace scene {
	Squares::Squares()
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
			std::make_unique<GLCore::Shader>("res/squares.vertex.glsl",
				"res/squares.fragment.glsl");

		m_VertexBufferLayout->Push<float>(2);
		m_VertexBufferLayout->Push<float>(2);
		m_VertexArray->AddBuffer(*m_VertexBuffer, *m_VertexBufferLayout);

		m_VertexBuffer->UpdateData(positions, 4 * 4 * sizeof(float), 0);
		m_IndexBuffer->UpdateData(indicies, 2 * 3 * sizeof(unsigned int), 0);
	}

	Squares::~Squares() {

	}

	void Squares::OnRender() {
		m_Renderer->Clear();
		//for every quad, do the following:
		for (int i = 0; i < m_QuadCount; i++) {
			int x = m_Transforms.at(i).first;
			int y = m_Transforms.at(i).second;
			m_Model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0));
			glm::mat4 mvp = m_Projection * m_Model * m_View;
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("u_MVP", mvp);
			std::array<float, 4> color = m_Colors.at(i);
			m_Shader->SetUniform4f("u_Color", color.at(1), color.at(2), color.at(3), 1.0);
			m_Renderer->DrawDynamic(*m_VertexArray, *m_IndexBuffer, 6, *m_Shader);
		}
	}

	void Squares::OnImGuiRender() {
		ImGui::Text("Number of squares");
		if (ImGui::SliderInt("##quad", &m_QuadCount, 1, 100)) {
			m_Transforms.clear();
			m_Colors.clear();
			for (int i = 0; i < m_QuadCount; i++) {
				std::pair<int, int> coordinate;
				coordinate.first = rand() % 1920;
				coordinate.second = rand() % 1080;
				m_Transforms.push_back(coordinate);
				float r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
				float g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
				float b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
				m_Colors.push_back({ 1.0f, r, g, b });
			}
		}
	}
}