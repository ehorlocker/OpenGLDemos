#pragma once

#include <memory>
#include "Scene.h"
#include "GLCore.h"

namespace scene {
	class BatchRendering : public Scene {
	public:
		BatchRendering();
		~BatchRendering();

		void OnRender() override;
		void OnImGuiRender() override;

	private:
		int m_QuadCount;
		int m_DrawCalls;
		glm::mat4 m_Projection;
		glm::mat4 m_Model;
		glm::mat4 m_View;
		std::unique_ptr<GLCore::DynamicVertexBuffer> m_VertexBuffer;
		std::unique_ptr<GLCore::VertexBufferLayout> m_VertexBufferLayout;
		std::unique_ptr<GLCore::VertexArray> m_VertexArray;
		std::unique_ptr<GLCore::DynamicIndexBuffer> m_IndexBuffer;
		std::unique_ptr<GLCore::Renderer> m_Renderer;
		std::unique_ptr<GLCore::Shader> m_Shader;
	};
}