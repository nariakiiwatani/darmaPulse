#pragma once

#include "SceneBase.h"

class ResultScene : public SceneBase
{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
};

/* EOF */