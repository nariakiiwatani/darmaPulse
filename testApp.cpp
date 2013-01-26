#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	manager_.setup();
}

//--------------------------------------------------------------
void testApp::update(){
	manager_.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	manager_.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	manager_.keyPressed(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	manager_.keyReleased(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	manager_.mouseMoved(x,y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	manager_.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	manager_.mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	manager_.mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}