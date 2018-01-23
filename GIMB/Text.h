#pragma once
#include <allegro.h>
class Text
{
	BITMAP *buffer;
	FONT f;
public:
	Text(BITMAP *buffer, FONT f);
	void print(const char* title, int x, int y, unsigned int r, unsigned int g, unsigned int b);
	const char* inputText();
	~Text();
};

