#ifndef ULTIMATETTT_SCENE_H
#define ULTIMATETTT_SCENE_H

class SceneManager;

class Scene {
public:
    explicit Scene(SceneManager* sceneManager) : sceneManager(sceneManager) {}
    virtual ~Scene() = default;

    virtual void Draw() = 0;
    virtual void Update() = 0;

protected:
    SceneManager* sceneManager;
};

#endif //ULTIMATETTT_SCENE_H
