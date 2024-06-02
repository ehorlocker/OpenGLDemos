#pragma once

#include "Scene.h"
#include "DynamicVertexBuffer.h"

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
		GLCore::DynamicVertexBuffer* m_DynamicVertexBuffer;
	};
}