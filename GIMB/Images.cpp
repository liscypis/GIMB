#include "Images.h"



Images::Images(BITMAP *buffer)
{
	this->buffer = buffer;
	
}

void Images::loadImage(const char* path)
{
	this->image = load_bmp(path, palette);
	if (!this->image) {
		allegro_message("Couldn't load image!",allegro_error);
		destroy_bitmap(this->image);
		allegro_exit();
		exit(0);
	}
}

void Images::printImage(int x, int y, int w, int h){
	blit(this->image, this->buffer, 0, 0, x, y, w, h);
}
void Images::saveImage()
{
	 BITMAP *bmp;
	 bmp = create_sub_bitmap(buffer, 620, 160, 512, 512);
	 save_bitmap("zapisany.bmp", bmp, palette);
}

Images::~Images()
{
}
