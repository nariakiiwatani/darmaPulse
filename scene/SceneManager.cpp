#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "GameoverScene.h"

void SceneManager::setup()
{
	scenes_[0] = new TitleScene();
	scenes_[1] = new GameScene();
	scenes_[2] = new ResultScene();
	scenes_[3] = new GameoverScene();
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