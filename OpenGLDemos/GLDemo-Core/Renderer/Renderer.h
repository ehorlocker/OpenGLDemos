#pragma once

#include "VertexArray.h"
#include "StaticIndexBuffer.h"
#include "DynamicIndexBuffer.h"
#include "Shader.h"

namespace GLCore {
	class Renderer {
	public:
		Renderer() {}
		~Renderer() {}

		void Clear();
		void DrawStatic(const VertexArray& va, const StaticIndexBuffer& ib, const Shader& shader) const;
		void DrawDynamic(const VertexArray& va, const DynamicIndexBuffer& ib, const unsigned int ibCount, const Shader& shader) const;
	};
}