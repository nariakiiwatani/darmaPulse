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
	ard.connect("COM4", 57600);
	ofAddListener(ard.EInitialized, this, &Arduino::setup );
	calibrateFlag = false;
	bSetupArduino = false;
	calCount = 0;
	threshold = 0;
	ignoreCount = 0;
	pResult = false;
}
void Arduino::setup(const int & version) {
	ofRemoveListener(ard.EInitialized, this, &Arduino::setup);
	
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ard.sendAnalogPinReporting(1, ARD_ANALOG);
    bSetupArduino = true;
}

bool Arduino::isBeating(){
	ard.update();
	raw[0] = ard.getAnalog(0);
	int val = raw[0];
	
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
	cout << (int)(val - threshold) << endl;
	
	ignoreCount++;
	bool rslt = val > threshold;
	
	
	if(ignoreCount<10){
		return false;
	}else{
		if(rslt) ignoreCount = 0;
		return rslt;
	}
}

bool Arduino::isGameClear()
{
	raw[1] = ard.getAnalog(1);

	return raw[1] > 500;
}

void Arduino::calibrate(){
	for (int i=0; i<BUFFER_SIZE; i++) {
		buffer[i] = 0;
	}
	calCount = 0;
	calibrateFlag = true;
}

int Arduino::getRawData(int index)
{
	return raw[index];
}
int Arduino::getCalibratedData(int index)
{
	if(index==0) {
		return raw[0] - threshold;
	}
	else if(index==1) {
		return raw[1]-400;
	}
	return 0;
}