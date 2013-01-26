#include "counter.h"

//--------------------------------------------------------------
void counter::setup(){
    ofBackground(255,255,255);
    drmCounts = 0;

}

//--------------------------------------------------------------
void counter::update(){
    if (drmCounts > 9) {
        drmCounts = 0;
    }
    
}

//--------------------------------------------------------------
void counter::draw(){
    if (drmCounts == 9) {
        ofSetColor(255, 0, 0);
    }else{
        ofSetColor(0,0,0);
    }
	ofCircle(drmCounts * 50, ofGetHeight()/2, 100);
    

}
//--------------------------------------------------------------
void counter::mousePressed(int x, int y, int button){
    drmCounts += 1;
    
}
