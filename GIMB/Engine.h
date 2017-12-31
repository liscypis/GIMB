#pragma once
class Engine
{
private:
	int x;
	int y;
	int vX = 0;
	int vY = 0;
	bool exit = false;
	void running();
	void createWindow(const char* title, int x, int y, int vX, int Vy);
	void createWindow(char title, int x, int y, int vX, int vY, char * mode);
	void deleteWindow();
public:
	Engine(const char* title, int x, int y);
	~Engine();
};
