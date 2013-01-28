#include "ResultScene.h"
#include "ofGraphics.h"

void ResultScene::setup()
{
}
void ResultScene::update()
{

}
void ResultScene::draw()
{
	ofBackground(ofColor::black);
}

void ResultScene::mousePressed(int x, int y, int button){
    next_scene_ = SCENE_ID_TITLE;
}

/* EOF */