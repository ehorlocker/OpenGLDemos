#pragma once

#include <functional>
#include <vector>
#include <string>
#include "Scene.h"

namespace scene {
	struct SceneObject {
		std::string name;
		std::function<Scene* ()> getNewScene;

		SceneObject(std::string sceneName, std::function<Scene* ()> sceneFunction) :
			name(sceneName), getNewScene(sceneFunction) {
		}
	};

	class MainMenu : public Scene {
	public:
		MainMenu(Scene*& currentScenePointer);

		void OnRender() override;
		void OnImGuiRender() override;

		template<typename T>
		void RegisterTest(const std::string& name) {
			SceneObject sceneObject(name, []() { return new T(); });
			m_Scenes.push_back(sceneObject);
		}
	private:
		Scene*& currentScene;
		std::vector<SceneObject> m_Scenes;
	};
}
