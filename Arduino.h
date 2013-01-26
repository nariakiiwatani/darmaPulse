/*
 *  Arduino.h
 *  darmaPulse
 *
 *  Created by 南部 晃史 on 13/01/26.
 *  Copyright 2013 九州大学. All rights reserved.
 *
 */

#ifndef _DARMA_PALSE_ARDUINO
#define _DARMA_PALSE_ARDUINO
#define BUFFER_SIZE 32

#include "ofMain.h"
#include "ofEvents.h"

class Arduino {
private:
	ofArduino ard;
	bool bSetupArduino;
	void setup(const int & version);
	void update();
	int buffer[BUFFER_SIZE];
	bool calibrateFlag;
	int calCount;
	
	bool pResult;
	int ignoreCount;
	
	float threshold;
public:
	Arduino();
	bool isBeating();
	void calibrate();
};

#endif