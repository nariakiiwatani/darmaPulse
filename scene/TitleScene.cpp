#include "TitleScene.h"

void TitleScene::setup()
{
	SceneBase::setup();

}
void TitleScene::update()
{

}
void TitleScene::draw()
{

}

void TitleScene::mousePressed(int x, int y, int button){
    next_scene_ = SCENE_ID_GAME;
}

/* EOF */