#include "DarmaPlayer.h"
#include "ofMain.h"

void DarmaPlayer::setup()
{
	is_moving_ =
	is_goal_ =
	is_gameover_ = false;

#ifndef NOUSE_CAMERA
	openni_.setup();
	image_.setup(&openni_);
	depth_.setup(&openni_);
	user_.setup(&openni_);
	openni_.setMirror(true);
	depth_.setDepthColoring(COLORING_GREY);
//	user_.setUseMaskPixels(true);
	user_pix_.allocate(image_.getTexture()->getWidth(), image_.getTexture()->getHeight(), OF_PIXELS_RGBA);
	user_tex_.allocate(user_pix_);
#endif // NOUSE_CAMERA
}

void DarmaPlayer::update()
{
#ifndef NOUSE_CAMERA
	openni_.update();
	image_.update();
	depth_.update();
	user_.update();
	if(user_.getNumberOfTrackedUsers() > 0) {
		const unsigned char* img_pix = image_.getPixels();
		const unsigned char* dph_pix = user_.getUserPixels();
		int w = user_.getWidth();
		int h = user_.getHeight();
		int move_pix = 0;
		int valid_pix = 0;
		for(int i = 0, max = w*h; i < max; ++i) {
			int x = i%w;
			int y = i/w;
			if(dph_pix[i] == 0) {
				if(user_pix_.getColor(x, y) != ofColor(0,0,0,0)) {
					++move_pix;
					user_pix_.setColor(x, y, ofColor(0,0,0,0));
				}
			}
			else {
				++valid_pix;
				const ofColor& prev = user_pix_.getColor(x, y);
				const ofColor next(img_pix[i*3], img_pix[i*3+1], img_pix[i*3+2]);
				if((abs(prev.r-next.r) > 100)
					|| (abs(prev.g-next.g) > 100)
					|| (abs(prev.b-next.b) > 100)) {
						++move_pix;
				}
				user_pix_.setColor(x, y, next);
			}
		}
		is_moving_ = move_pix/(float)(valid_pix) > 0.2f;
	}
	else {
		is_moving_ = false;
	}
#endif // NOUSE_CAMERA
}

void DarmaPlayer::draw()
{
#ifndef NOUSE_CAMERA
	int w = 1024;
	int h = 768;
	ofSetColor(255);
	ofRect(0,0,w,h);
	user_tex_.loadData(user_pix_);
	user_tex_.draw(0,0,w,h);
#endif // NOUSE_CAMERA
}