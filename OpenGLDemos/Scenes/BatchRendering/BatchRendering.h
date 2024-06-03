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
		unsigned int m_QuadCount;
		unsigned int m_DrawCalls;
		std::unique_ptr<GLCore::DynamicVertexBuffer> m_VertexBuffer;
		std::unique_ptr<GLCore::VertexBufferLayout> m_VertexBufferLayout;
		std::unique_ptr<GLCore::VertexArray> m_VertexArray;
		std::unique_ptr<GLCore::DynamicIndexBuffer> m_IndexBuffer;
		std::unique_ptr<GLCore::Renderer> m_Renderer;
	};
}