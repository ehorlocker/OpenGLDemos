#include "MainMenu.h"
#include "glad/glad.h"
#include "imgui.h"

namespace scene {
	MainMenu::MainMenu(Scene*& currentScenePointer)
		: currentScene(currentScenePointer) {
	}

	void MainMenu::OnRender() {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void MainMenu::OnImGuiRender() {
		for (auto& scene : m_Scenes) {
			if (ImGui::Button(scene.name.c_str())) {
				currentScene = scene.getNewScene();
			}
		}
	}
}