#pragma once

class Player
{
public:
	void setup();
	bool isMoving() { return is_moving_; }
	bool isGoal() { return is_goal_; }

// デバッグ用関数
	void setMoving(bool set) { is_moving_ = set;}
	void setGoal(bool set) { is_goal_ = set;}

private:
	bool is_moving_;
	bool is_goal_;
};

/* EOF */