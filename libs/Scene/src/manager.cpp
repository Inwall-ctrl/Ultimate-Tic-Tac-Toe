#include "Scene/manager.h"
#include <iostream>

void SceneManager::AddScene(const std::string& name, std::shared_ptr<Scene> scene) {
    scenes[name] = scene;
}

void SceneManager::SwitchTo(const std::string& name) {
    if (scenes.find(name) != scenes.end()) {
        currentScene = scenes[name];
        nextSceneName.clear();
    } else {
        std::cerr << "Scene " << name << " not found!\n";
    }
}

void SceneManager::RequestSwitchTo(const std::string& name) {
    nextSceneName = name;
}

void SceneManager::UpdateCurrentScene() {
    if (currentScene) {
        currentScene->Update();
    }
    if (!nextSceneName.empty()) {
        SwitchTo(nextSceneName);
    }
}

void SceneManager::DrawCurrentScene() {
    if (currentScene) {
        currentScene->Draw();
    }
}
