#include "BatchRendering.h"

namespace scene {
	BatchRendering::BatchRendering()
		: m_QuadCount(0), m_DrawCalls(1)
	{
		m_DynamicVertexBuffer = 
			std::make_unique<GLCore::DynamicVertexBuffer>(GLCore::DynamicVertexBuffer(1024));
	}

	BatchRendering::~BatchRendering()
	{

	}

	void BatchRendering::OnRender()
	{
	}

	void BatchRendering::OnImGuiRender()
	{
	}
}