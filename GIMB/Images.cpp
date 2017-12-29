#include "Images.h"



Images::Images(BITMAP *buffer, const char* path)
{
	this->buffer = buffer;
	this->image = load_bmp(path, palette);
	if (!this->image) {
		allegro_message("Couldn't load image!",allegro_error);
		destroy_bitmap(this->image);
	}
}

void Images::printImage(int x, int y, int w, int h){
	blit(this->image, this->buffer, 0, 0, x, y, w, h);
}

Images::~Images()
{
}
