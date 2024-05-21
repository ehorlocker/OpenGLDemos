#include "MainMenu.h"
#include "glad.h"

namespace scene {
	MainMenu::MainMenu(Scene*& currentScenePointer)
		: currentScene(currentScenePointer) {
	}

	void MainMenu::OnRender() {
		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void MainMenu::OnImGuiRender() {
		for (auto& scene : m_Scenes) {
			if (ImGui::Button(scene.name.c_str())) {
				currentScene = scene.getNewTest();
			}
		}
	}
}