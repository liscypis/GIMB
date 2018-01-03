#include "Buffer.h"

#include <allegro.h>

Buffer::Buffer()
{
	this->buffer = create_bitmap(SCREEN_W, SCREEN_H);
}

BITMAP * Buffer::getBuff()
{
	return this->buffer;
}



void Buffer::clear() {
	blit(this->buffer, screen, 0, 0, 0, 0, this->buffer->w, this->buffer->h);
	clear_to_color(this->buffer,makecol(0,153,153));
}

Buffer::~Buffer()
{
}