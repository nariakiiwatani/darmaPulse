#include "GameScene.h"

void GameScene::setup()
{
	SceneBase::setup();
	player_.setup();
    arduino_.calibrate();
    sound_.setup();
}
void GameScene::update()
{
    if(arduino_.isBeating()) {
        
    }
    sound_.update();
    player_.update();
	if(player_.isGoal()) {
		next_scene_ = SCENE_ID_RESULT;
	}
}

void GameScene::draw()
{
    player_.draw();
}

//--------------------------------------------------------------
void GameScene::keyPressed(int key){
}

//--------------------------------------------------------------
void GameScene::keyReleased(int key){
}

//--------------------------------------------------------------
void GameScene::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void GameScene::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void GameScene::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void GameScene::mouseReleased(int x, int y, int button){
}

/* EOF */