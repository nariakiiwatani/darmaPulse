#pragma once

#include "SceneManager.h"

class SceneBase
{
public:
	virtual void setup();
	virtual void update(){}
	virtual void draw(){}
	SceneId getNextSceneId(){ return next_scene_; }
private:
	SceneId next_scene_;
};

/* EOF */