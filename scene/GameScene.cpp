#include "GameScene.h"

void GameScene::setup()
{
	player_.setup();
    sound_.setup();
    counter_.setup();
}

void GameScene::ready()
{
    SceneBase::ready();
    mouse_presed_ = false;
    player_.setGoal(false);
    player_.setGameover(false);
    player_.setMoving(false);
    counter_.drmCounts = -1;
    sound_.mousePressed = false;
    arduino_.calibrate();
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
    else if(player_.isMoving() && counter_.drmCounts == 9) {
        player_.setGameover(true);
    }
    if(player_.isGameover()) {
		next_scene_ = SCENE_ID_GAMEOVER;
    }
    
    mouse_presed_ = false;
    player_.setMoving(false);
}

void GameScene::draw()
{
    ofBackground(255,255,255);
    player_.draw();
    counter_.draw();
}

//--------------------------------------------------------------
void GameScene::keyPressed(int key){
    if(key == ' ') {
        arduino_.calibrate();
    }
    else if(key == OF_KEY_RETURN) {
        player_.setGoal(true);
    }
}

//--------------------------------------------------------------
void GameScene::keyReleased(int key){
}

//--------------------------------------------------------------
void GameScene::mouseMoved(int x, int y ){
#ifdef NOUSE_CAMERA
    player_.setMoving(true);
#endif // NOUSE_CAMERA
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