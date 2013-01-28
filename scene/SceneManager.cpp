#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "GameoverScene.h"

void SceneManager::setup()
{
	sound_.loadSound("horor.wav");
	sound_.setVolume(0.3f);
	sound_.setLoop(true);
	sound_.play();

	scenes_[SCENE_ID_TITLE] = new TitleScene();
	scenes_[SCENE_ID_GAME] = new GameScene();
	scenes_[SCENE_ID_RESULT] = new ResultScene();
	scenes_[SCENE_ID_GAMEOVER] = new GameoverScene();
	current_ = scenes_[SCENE_ID_GAME];
	current_->setup();
    current_->ready();

//	scenes_[SCENE_ID_TITLE]->setBG();
//	scenes_[SCENE_ID_GAME]->setBG();
//	scenes_[SCENE_ID_RESULT]->setBG();
//	scenes_[SCENE_ID_GAMEOVER]->setBG();
}

void SceneManager::update()
{
	current_->update();
    SceneId next = current_->getNextSceneId();
	if(next != SCENE_CURRENT) {
		current_ = scenes_[next];
        current_->ready();
	}
}
void SceneManager::draw()
{
	current_->drawBG();
	current_->draw();
}

//--------------------------------------------------------------
void SceneManager::keyPressed(int key){
	current_->keyPressed(key);
}

//--------------------------------------------------------------
void SceneManager::keyReleased(int key){
	current_->keyReleased(key);
}

//--------------------------------------------------------------
void SceneManager::mouseMoved(int x, int y ){
	current_->mouseMoved(x,y);
}

//--------------------------------------------------------------
void SceneManager::mouseDragged(int x, int y, int button){
	current_->mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void SceneManager::mousePressed(int x, int y, int button){
	current_->mousePressed(x,y,button);
}

//--------------------------------------------------------------
void SceneManager::mouseReleased(int x, int y, int button){
	current_->mouseReleased(x,y,button);
}

/* EOF */