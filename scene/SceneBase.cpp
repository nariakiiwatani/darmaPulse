#include "SceneBase.h"
#include "ofMain.h"

void SceneBase::ready()
{
	next_scene_ = SCENE_CURRENT;
}

void SceneBase::drawBG()
{
	if(background_.isAllocated()) {
		background_.draw(0,0,ofGetWidth(),ofGetHeight());
	}
}

void SceneBase::setBG(string path)
{
	ofLoadImage(background_, path);
}

/* EOF */