#pragma once

#include "Scene.h"

namespace scene {
	class ClearColor : public Scene {
	public:
		ClearColor();

		void OnRender() override;
		void OnImGuiRender() override;

	private:
		float m_Color[4];
	};
}