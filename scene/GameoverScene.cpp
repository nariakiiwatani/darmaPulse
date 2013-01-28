#include "GameoverScene.h"
#include "ofGraphics.h"

void GameoverScene::setup()
{
}
void GameoverScene::update()
{

}
void GameoverScene::draw()
{
	ofBackground(ofColor::red);
}

void GameoverScene::mousePressed(int x, int y, int button){
    next_scene_ = SCENE_ID_TITLE;
}

/* EOF */