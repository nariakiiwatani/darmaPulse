#pragma once

#include "SceneManager.h"

class SceneBase
{
public:
	virtual void setup();
    virtual void ready();
	virtual void update(){}
	virtual void draw(){}
	SceneId getNextSceneId(){ return next_scene_; }

	virtual void keyPressed  (int key){}
	virtual void keyReleased(int key){}
	virtual void mouseMoved(int x, int y ){}
	virtual void mouseDragged(int x, int y, int button){}
	virtual void mousePressed(int x, int y, int button){}
	virtual void mouseReleased(int x, int y, int button){}

protected:
	SceneId next_scene_;
};

/* EOF */