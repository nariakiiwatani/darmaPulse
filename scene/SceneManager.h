#pragma once

enum SceneId {
	SCENE_ID_TITLE,
	SCENE_ID_GAME,
	SCENE_ID_RESULT,
	SCENE_ID_GAMEOVER,

	SCENE_ID_NUM,

	SCENE_CURRENT,
};

class SceneBase;
class SceneManager
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
	SceneBase* scenes_[SCENE_ID_NUM];
    SceneBase* current_;
};

/* EOF */