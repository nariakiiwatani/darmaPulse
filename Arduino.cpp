/*
 *  Arduino.cpp
 *  darmaPulse
 *
 *  Created by 南部 晃史 on 13/01/26.
 *  Copyright 2013 九州大学. All rights reserved.
 *
 */

#include "Arduino.h"

Arduino::Arduino(){
	ard.connect("/dev/tty.usbmodem411", 57600);
	ofAddListener(ard.EInitialized, this, &Arduino::setup );
	calibrateFlag = false;
	bSetupArduino = false;
	calCount = 0;
	threshold = 0;
	pResult = false;
}
void Arduino::setup(const int & version) {
	ofRemoveListener(ard.EInitialized, this, &Arduino::setup);
	
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    bSetupArduino = true;
}

bool Arduino::isBeating(){
	ard.update();
	int val = ard.getAnalog(0);
	
	if (calibrateFlag){
		if(calCount < BUFFER_SIZE) {
			buffer[calCount] = val;
			calCount ++;
			return false;
		}else{
			int sum = 0;
			for (int i=0; i<BUFFER_SIZE; i++) {
				sum += buffer[i];
			}
			threshold = (float)sum/BUFFER_SIZE+10;
			calibrateFlag = false;
		}
	}
	cout << val - threshold << endl;
	
	ignoreCount++;
	bool rslt = val > threshold;
	
	
	if(ignoreCount<30){
		return false;
	}else{
		if(rslt) ignoreCount = 0;
		return rslt;
	}
	
	
}

void Arduino::calibrate(){
	for (int i=0; i<BUFFER_SIZE; i++) {
		buffer[i] = 0;
	}
	calCount = 0;
	calibrateFlag = true;
}