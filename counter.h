#pragma once

#include "ofColor.h"

class Circle
{
public:
	void setPos(int x, int y);
	void setColor(const ofColor& col);
	void setSize(float size);
	void update();
	void setAlpha(int alpha);
	void draw();
private:
	int x_, y_;
	ofColor color_;
	float size_;
};

class counter {

	public:
		void setup();
		void update();
		void draw();

		void setCircleAlpha(float alpha);

		void mousePressed(int x, int y, int button);
    
        int drmCounts;

private:
	Circle circle[10];
	int waitCount;
	int waitMax;
	int phase;
};
