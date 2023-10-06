#pragma once
#include "AbstractScene.h"

class SceneManager : public AbstractScene {
private:

	AbstractScene* mScene;

public:

	SceneManager(AbstractScene* scene) : mScene(scene) {}
	~SceneManager() {
		delete mScene;
	}
	AbstractScene* Update() override;
	void Draw() const override;
};