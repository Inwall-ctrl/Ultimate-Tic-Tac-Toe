#ifndef ULTIMATETTT_MANAGER_H
#define ULTIMATETTT_MANAGER_H

#include <unordered_map>
#include <memory>
#include <string>
#include "Scene.h"

class SceneManager {
public:
    void AddScene(const std::string& name, std::shared_ptr<Scene> scene);
    void SwitchTo(const std::string& name);
    void RequestSwitchTo(const std::string& name);
    void UpdateCurrentScene();
    void DrawCurrentScene();

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;
    std::string nextSceneName;
};

#endif //ULTIMATETTT_MANAGER_H
