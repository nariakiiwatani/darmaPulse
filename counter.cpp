#include "counter.h"
#include "ofMain.h"

void Circle::setPos(int x, int y)
{
	x_ = x;
	y_ = y;
}

void Circle::setColor(const ofColor& col)
{
	color_ = col;
}

void Circle::setSize(float size)
{
	size_ = size;
}

void Circle::update()
{
}

void Circle::setAlpha(int alpha)
{
	color_.a = alpha;
}

void Circle::draw()
{
	ofSetColor(color_);
	ofEllipse(x_, y_, size_, size_);
}



//--------------------------------------------------------------
void counter::setup(){
    drmCounts = 0;
	phase = 0;

	for(int i = 0; i < 10; ++i) {
		circle[i].setColor(i==9 ? ofColor::red : ofColor::black);
		circle[i].setSize(ofRandom(160,300));
		circle[i].setPos(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	}

}

void counter::setCircleAlpha(float alpha)
{
	for(int i = 0; i < 9; ++i) {
		circle[i].setAlpha(alpha);
	}
}

//--------------------------------------------------------------
void counter::update(){
	switch(phase) {
	case 0:
		if(drmCounts == 9) {
			for(int i = 0; i < 10; ++i) {
				circle[i].setColor(ofColor::red);
			}
			phase=1;
			waitCount = 0;
			waitMax = ofRandom(2,8);
		}
		break;
	case 1:
		if(waitCount >= waitMax) {
			setup();
		}
		break;
	}

}

//--------------------------------------------------------------
void counter::draw(){
//    if (drmCounts == 9) {
//        ofSetColor(255, 0, 0);
//    }else{
//        ofSetColor(0,0,0);
//    }
//	ofCircle(drmCounts * 50, ofGetHeight()/2, 100);

    for(int i = 0; i <= drmCounts; ++i) {
		circle[i].draw();
	}

}
//--------------------------------------------------------------
void counter::mousePressed(int x, int y, int button){
	switch(phase) {
	case 0:
	    drmCounts += 1;
		break;
	case 1:
		++waitCount;
		break;
	}
}
