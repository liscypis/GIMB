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
	static int mask[];
	static int power;
	static int cursor_position_x;
	static int cursor_position_y;

public:
	Filters();
	static int user_mask[];
	static void linear_filters(BITMAP* buffer,const char* type);
	static void negative_filter(BITMAP* buffer);
	static void minimal_filter(BITMAP* buffer);
	static void maxinum_filter(BITMAP* buffer);
	static void fill_array();
	static void set_cursor_position_x(int x);
	static void set_cursor_position_y(int y);
	static int get_cursor_position_x();
	static int get_cursor_position_y();
	static const char * to_string_cursor_position();
	static const char* to_string_power();
	static void set_power(int p);
	static int get_power();

	static int get_mask(int i); 


	~Filters();
};

