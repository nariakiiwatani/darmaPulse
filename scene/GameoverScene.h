#pragma once

#include "SceneBase.h"

class GameoverScene : public SceneBase
{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
};

/* EOF */