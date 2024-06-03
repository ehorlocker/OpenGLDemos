#pragma once

#include "Scene.h"
#include "GLCore.h"

namespace scene {
	class ClearColor : public Scene {
	public:
		ClearColor();
		~ClearColor();

		void OnRender() override;
		void OnImGuiRender() override;

	private:
		float m_Color[4];
	};
}