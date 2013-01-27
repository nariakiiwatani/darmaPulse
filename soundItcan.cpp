//
//  soundItcan.cpp
//  darmaPulse
//
//  Created by 伊藤 慎一郎 on 13/01/26.
//
//

#include "soundItcan.h"


//--------------------------------------------------------------
void soundItcan::setup(){
    
    for (i=0; i<10 ;i++){
        sound[i][0].loadSound("sounds/"+ofToString(i)+".wav");
        sound[i][1].loadSound("sounds/0"+ofToString(i)+".wav");
        ofLog();
    }
    
    for (i=0; i<10 ;i++){
        sound[i][0].setVolume(0.75f);
        sound[i][1].setVolume(0.75f);
    }

    for (i=0; i<10 ;i++){
        sound[i][0].setMultiPlay(true);
        sound[i][1].setMultiPlay(true);
    }
}

//--------------------------------------------------------------
void soundItcan::update(){
    
    
    
	// update the sound playing system:
	ofSoundUpdate();
    
    /*
    if(mousePressed){
        count++;
        
        if(count >= 10){
            count=0;
                    }
    }*/
    
    if(count >= 10){
        count=0;
    }
    if (mousePressed){
        
        if (count < 10 && count >= 0){
        ofLog(OF_LOG_WARNING ,ofToString("countは"+count));
        int j = ofRandom(2);
        sound[count][j].play();
   
        } else {
//            soundE.play();
        }
             
    }
    
    mousePressed = false;
}

