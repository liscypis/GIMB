#pragma once
#include <allegro.h>

class Font
{
	FONT *newFont;
	PALLETE palette;
public:
	Font(const char* filename);
	FONT* getFont();
	~Font();
};
