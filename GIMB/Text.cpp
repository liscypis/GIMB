#include "Text.h"
#include <allegro.h>
#include "Font.h"
#include "Engine.h"

Text::Text(BITMAP *buffer, FONT f)
{
	this->f = f;
	this->buffer = buffer;
}

void Text::print(const char* title, int x, int y, unsigned r, unsigned g, unsigned b) {
	textprintf_ex(this->buffer, &this->f, x, y, makecol(r, g, b), -1, title);
}


Text::~Text()
{
}