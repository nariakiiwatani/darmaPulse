#pragma once

class counter {

	public:
		void setup();
		void update();
		void draw();

		void mousePressed(int x, int y, int button);
    
        int drmCounts;
};
