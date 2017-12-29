#include "Font.h"



Font::Font(const char *filename)
{
	this->newFont = load_font(filename, palette, NULL);
	if (newFont==0)
	{
		allegro_message("ERROR: Font has not been created\n", allegro_error);
		allegro_exit();
	}
}

FONT* Font::getFont()
{
	return newFont;
}
Font::~Font()
{
}