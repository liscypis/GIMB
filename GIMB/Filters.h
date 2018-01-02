#pragma once
#include <allegro.h>
class Filters
{
	static const int x0 = 100;
	static const int x_margin = 612;
	static const int y0 = 160;
	static const int y_margin = 672;
	static int average_mask[];
	static int horizontal_edges_mask[];
	static int vertical_edges_mask[];
	static int random_mask[];
	static int mask[];
	static const int POWER = 200;
public:
	Filters();
	static void linear_filters(BITMAP* buffer,const char* type);
	static void negative_filter(BITMAP* buffer);
	static void minimal_filter(BITMAP* buffer);
	static void maxinum_filter(BITMAP* buffer);
	static void fill_array();
	static int get_mask();

	~Filters();
};

