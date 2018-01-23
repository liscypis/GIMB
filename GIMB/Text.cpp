#include <string>
#include "Text.h"
#include <allegro.h>
#include "Font.h"
#include "Engine.h"
#include "Filters.h"


Text::Text(BITMAP* buffer, FONT f)
{
	this->f = f;
	this->buffer = buffer;
}

void Text::print(const char* title, int x, int y, unsigned int r, unsigned int g, unsigned int b)
{
	textprintf_ex(this->buffer, &this->f, x, y, makecol(r, g, b), -1, title);
}

void Text::inputMatrix(Buffer* b)
{
	b->clear();
	b->clear();
	clear_keybuf();
	char text[70];
	int caret = 0;
	int num;
	int i = 0;
	bool isMinus = false;
	do
	{
		
		print("Podaj macierz 5x5", 330, 300, 0, 255, 0);
		if (keypressed())
		{
			int newkey = readkey();
			char ASCII = newkey & 0xff;
			if (ASCII >= 48 && ASCII <= 57)
			{
				if (ASCII == 48) num = 0;
				if (ASCII == 49) num = 1;
				if (ASCII == 50) num = 2;
				if (ASCII == 51) num = 3;
				if (ASCII == 52) num = 4;
				if (ASCII == 53) num = 5;
				if (ASCII == 54) num = 6;
				if (ASCII == 55) num = 7;
				if (ASCII == 56) num = 8;
				if (ASCII == 57) num = 9;

				if (isMinus)
					Filters::user_mask[i] = -num;
				else
					Filters::user_mask[i] = num;

				isMinus = false;
				i++;
			}
			if (ASCII == 45)
			{
				isMinus = true;
			}

			text[caret] = ASCII;
			caret++;
			text[caret] = '\0';

			print(text, 430, 325, 0, 255, 0);
			b->clear();
		}
	}
	while (i < 25);
}

const char* Text::inputText(Buffer* b)
{
	static char edittext[50];
	int caret = 0;
	do
	{
		print("Podaj nazwe pliku, a nastepnie potwierdz Enterem", 330, 300, 0, 255, 0);
		if (keypressed())
		{
			int newkey = readkey();
			char ASCII = newkey & 0xff;
			char scancode = newkey >> 8;
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
			print(edittext, 550, 325, 0, 255, 0);
			b->clear();
		}
	}
	while (!key[KEY_ENTER]);
	return edittext;
}

void Text::printMatrix()
{
	int space = 1000;
	for (int i = 0; i < 25; i++)
	{
		std::string s = std::to_string(Filters::get_mask(i));
		const char* t = s.c_str();

		if (i < 5) print(t, space, 0, 0, 255, 0);
		if (i == 5) space = 1000;
		if (i >= 5 && i < 10) print(t, space, 25, 0, 255, 0);
		if (i == 10) space = 1000;
		if (i >= 10 && i < 15) print(t, space, 50, 0, 255, 0);
		if (i == 15) space = 1000;
		if (i >= 15 && i < 20) print(t, space, 75, 0, 255, 0);
		if (i == 20) space = 1000;
		if (i >= 20 && i < 25) print(t, space, 100, 0, 255, 0);

		space += 30;
	}
}


Text::~Text()
{
}
