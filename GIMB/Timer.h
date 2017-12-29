#pragma once
class Timer {
public:
	Timer(int speed);
	~Timer();
	void decreaseCount();
	int getCount();
private:
	static void timerUpdate(void* param);
	volatile int count;
};

