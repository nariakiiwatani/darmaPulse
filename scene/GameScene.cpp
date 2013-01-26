#include "GameScene.h"

void GameScene::setup()
{
	SceneBase::setup();
	player_.setup();
    arduino_.calibrate();
    sound_.setup();
    counter_.setup();
    mouse_presed_ = false;
}
void GameScene::update()
{
    if(mouse_presed_ || arduino_.isBeating()) {
        counter_.mousePressed(0,0,0);
        sound_.mousePressed = true;
        sound_.count = counter_.drmCounts;
    }
    counter_.update();
    sound_.update();
    player_.update();
	if(player_.isGoal()) {
		next_scene_ = SCENE_ID_RESULT;
	}
    mouse_presed_ = false;
}

void GameScene::draw()
{
    ofBackground(255,255,255);
    player_.draw();
    counter_.draw();
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
    mouse_presed_ = true;
}

//--------------------------------------------------------------
void GameScene::mouseReleased(int x, int y, int button){
}

/* EOF */