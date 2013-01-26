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
    
	sound0.loadSound("sounds/sound0.wav");
    sound1.loadSound("sounds/sound1.wav");
    sound2.loadSound("sounds/sound2.wav");
    sound3.loadSound("sounds/sound3.wav");
    sound4.loadSound("sounds/sound4.wav");
    sound5.loadSound("sounds/sound5.wav");
    sound6.loadSound("sounds/sound6.wav");
    sound7.loadSound("sounds/sound7.wav");
    sound8.loadSound("sounds/sound8.wav");
    sound9.loadSound("sounds/sound9.wav");
    soundE.loadSound("sounds/soundE.wav");
    
    sound0.setVolume(0.75f);
    sound1.setVolume(0.75f);
    sound2.setVolume(0.75f);
    sound3.setVolume(0.75f);
    sound4.setVolume(0.75f);
    sound5.setVolume(0.75f);
    sound6.setVolume(0.75f);
    sound7.setVolume(0.75f);
    sound8.setVolume(0.75f);
    sound9.setVolume(0.75f);
    soundE.setVolume(0.75f);
    
    sound0.setMultiPlay(true);
    sound1.setMultiPlay(true);
    sound2.setMultiPlay(true);
    sound3.setMultiPlay(true);
    sound4.setMultiPlay(true);
    sound5.setMultiPlay(true);
    sound6.setMultiPlay(true);
    sound7.setMultiPlay(true);
    sound8.setMultiPlay(true);
    sound9.setMultiPlay(true);
    soundE.setMultiPlay(true);
    

    
}

//--------------------------------------------------------------
void soundItcan::update(){
    
    
    
	// update the sound playing system:
	ofSoundUpdate();
    
    
    if(mousePressed){
        count++;
        
        if(count == 10){
            count=-0;
                    }
    }
    
    if (mousePressed){
        
        if (count < 10 && count >= 0){
        ofLog(OF_LOG_WARNING ,ofToString(count));
            
            switch(count){
                case 0:
                    sound0.play();
                    break;
                case 1:
                    sound1.play();
                    break;
                case 2:
                    sound2.play();
                    break;
                case 3:
                    sound3.play();
                    break;
                case 4:
                    sound4.play();
                    break;
                case 5:
                    sound5.play();
                    break;
                case 6:
                    sound6.play();
                    break;
                case 7:
                    sound7.play();
                    break;
                case 8:
                    sound8.play();
                    break;
                case 9:
                    sound9.play();
                    break;
            }
            
        } else {
            soundE.play();
        }
    }
    
    mousePressed = false;
}

