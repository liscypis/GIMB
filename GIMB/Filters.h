#pragma once
#include <allegro.h>
class Filters
{
	static const int x0 = 100;
	static const int x_margin = 612;
	static const int y0 = 160;
	static const int y_margin = 672;
public:
	Filters();
	static void average_filter(BITMAP* buffer);

	~Filters();
};

