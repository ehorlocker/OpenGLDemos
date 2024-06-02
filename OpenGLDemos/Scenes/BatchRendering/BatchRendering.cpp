#include "BatchRendering.h"

namespace scene {
	BatchRendering::BatchRendering()
		: m_QuadCount(0), m_DrawCalls(1)
	{
		m_DynamicVertexBuffer = new GLCore::DynamicVertexBuffer(1024);
	}

	BatchRendering::~BatchRendering()
	{
		delete m_DynamicVertexBuffer;
		m_DynamicVertexBuffer = nullptr;
	}

	void BatchRendering::OnRender()
	{
	}

	void BatchRendering::OnImGuiRender()
	{
	}
}