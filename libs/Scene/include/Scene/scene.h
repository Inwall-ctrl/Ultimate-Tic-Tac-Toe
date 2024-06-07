#ifndef ULTIMATETTT_SCENE_H
#define ULTIMATETTT_SCENE_H

class SceneManager; // Forward declaration

class Scene {
public:
    Scene(SceneManager* sceneManager) : sceneManager(sceneManager) {}
    virtual ~Scene() {}

    virtual void Draw() = 0;
    virtual void Update() = 0;

protected:
    SceneManager* sceneManager;
};

#endif //ULTIMATETTT_SCENE_H
