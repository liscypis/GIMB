#pragma once
#include <allegro.h>
class Images
{
	BITMAP *buffer, *image;
	PALLETE palette;
public:
	Images(BITMAP *buffer, const char* path);
	void printImage(int x, int y, int w, int h);
	~Images();
};


