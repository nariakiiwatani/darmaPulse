#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

void SceneManager::setup()
{
	scenes_[0] = new TitleScene();
	scenes_[1] = new GameScene();
	scenes_[2] = new ResultScene();
	current_ = scenes_[SCENE_ID_GAME];
	current_->setup();
}

void SceneManager::update()
{
	current_->update();
    SceneId next = current_->getNextSceneId();
	if(next != SCENE_CURRENT) {
		current_ = scenes_[next];
	}
}
void SceneManager::draw()
{
	current_->draw();
}

/* EOF */