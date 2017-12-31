#pragma once
#include <allegro.h>
class Listener
{
	char mode;
public:
	Listener();
	void choice(BITMAP *buffer);
	~Listener();
};

