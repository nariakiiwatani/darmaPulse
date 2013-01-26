#pragma once

enum SceneId {
	SCENE_ID_TITLE,
	SCENE_ID_GAME,
	SCENE_ID_RESULT,

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

private:
	SceneBase* scenes_[SCENE_ID_NUM];
    SceneBase* current_;
};

/* EOF */