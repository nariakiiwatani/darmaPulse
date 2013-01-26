#pragma once

class DarmaPlayer
{
public:
	void setup();
	bool isMoving() { return is_moving_; }
	bool isGoal() { return is_goal_; }
    
    void setMoving(bool set) { is_moving_ = set;}
	void setGoal(bool set) { is_goal_ = set;}
    
    void update();
    void draw();
    
private:
	bool is_moving_;
	bool is_goal_;
};

/* EOF */