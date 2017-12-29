#pragma once

#include <allegro.h>

class Buffer
{
	BITMAP *buffer;
public:
	Buffer();
	BITMAP *getBuff();
	void clear();
	~Buffer();
};

