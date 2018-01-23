#pragma once
#include <allegro.h>
class Images
{
	BITMAP *buffer, *image;
	PALLETE palette;
public:
	Images(BITMAP *buffer);
	void loadImage(const char* path);
	void printImage(int x, int y, int w, int h);
	void saveImage();
	~Images();
};


