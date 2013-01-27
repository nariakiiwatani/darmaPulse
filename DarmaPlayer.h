#pragma once

#define NOUSE_CAMERA

#ifndef NOUSE_CAMERA
#include "ofxOpenNI.h"
#include "ofTexture.h"
#endif // NOUSE_CAMERA

class DarmaPlayer
{
public:
	void setup();
	bool isMoving() { return is_moving_; }
	bool isGoal() { return is_goal_; }
    
    void setMoving(bool set) { is_moving_ = set;}
	void setGoal(bool set) { is_goal_ = set;}
    
    void update();
    void draw();
    
private:
	bool is_moving_;
	bool is_goal_;

#ifndef NOUSE_CAMERA
	ofxOpenNIContext openni_;
	ofxImageGenerator image_;
	ofxDepthGenerator depth_;
	ofxUserGenerator user_;

	ofTexture user_tex_;
	ofPixels user_pix_;
#endif // NOUSE_CAMERA
};

/* EOF */