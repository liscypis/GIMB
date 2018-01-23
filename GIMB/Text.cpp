#include "Text.h"
#include <allegro.h>
#include "Font.h"
#include "Engine.h"

Text::Text(BITMAP* buffer, FONT f)
{
	this->f = f;
	this->buffer = buffer;
}

void Text::print(const char* title, int x, int y, unsigned r, unsigned g, unsigned b)
{
	textprintf_ex(this->buffer, &this->f, x, y, makecol(r, g, b), -1, title);
}

const char* Text::inputText()
{
	char edittext[50];
	int caret = 0;
	do
	{
		if (keypressed())
		{
			int newkey = readkey();
			char ASCII = newkey & 0xff;
			char scancode = newkey >> 8;
			/* a character key was pressed; add it to the string */
			if (ASCII >= 32 && ASCII <= 126)
			{
				if (caret < 50 - 1)
				{
					edittext[caret] = ASCII;
					caret++;
					edittext[caret] = '\0';
				}
			}
			else if (scancode == KEY_BACKSPACE)
			{
				if (caret > 0) caret--;
				edittext[caret] = '\0';
			}
		}
	}  while(!key[KEY_ENTER]);
	return edittext;
}

	Text::~Text()
	{
	}
