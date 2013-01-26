#pragma once

#include "SceneBase.h"
#include "DarmaPlayer.h"
#include "Arduino.h"
#include "soundItcan.h"
#include "counter.h"

class GameScene : public SceneBase
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

private:
    Arduino arduino_;
    soundItcan sound_;
	DarmaPlayer player_;
    counter counter_;
    
    bool mouse_presed_;
};

/* EOF */