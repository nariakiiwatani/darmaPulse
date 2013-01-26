//
//  soundItcan.h
//  darmaPulse
//
//  Created by 伊藤 慎一郎 on 13/01/26.
//
//

#ifndef __darmaPulse__soundItcan__
#define __darmaPulse__soundItcan__

#include "ofMain.h"

class soundItcan {

public:
    void update();
    void setup();
    bool mousePressed;
    
    int count=0;
    
    ofSoundPlayer sound0;
    ofSoundPlayer sound1;
    ofSoundPlayer sound2;
    ofSoundPlayer sound3;
    ofSoundPlayer sound4;
    ofSoundPlayer sound5;
    ofSoundPlayer sound6;
    ofSoundPlayer sound7;
    ofSoundPlayer sound8;
    ofSoundPlayer sound9;
    ofSoundPlayer soundE;

};


#endif /* defined(__darmaPulse__soundItcan__) */
