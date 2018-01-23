#pragma once
#include <allegro.h>
#include "Images.h"
#include "Text.h"

class Listener
{
	char mode;
public:
	Listener();
	void choice(BITMAP* buffer, Text t, Images* i);
	~Listener();
};

