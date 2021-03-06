#include <ctime>
#include <string>
#include <iostream>
#include "Filters.h"


Filters::Filters()
{
}

int Filters::average_mask[] = {
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1
};

int Filters::horizontal_edges_mask[] = {
	// Sobel
	2, 2, 4, 2, 2,
	1, 1, 2, 1, 1,
	0, 0, 0, 0, 0,
	-1, -1, -2, -1, -1,
	-2, -2, -4, -2, -2
};

int Filters::vertical_edges_mask[] = {
	// Sobel
	2, 1, 0, -1, -2,
	3, 2, 0, -2, -3,
	4, 3, 0, -3, -4,
	3, 2, 0, -2, -3,
	2, 1, 0, -1, -2
};

int Filters::user_mask[25];
int Filters::cursor_position_x = x0 + 10;
int Filters::cursor_position_y = y0 + 10;
int Filters::power = 255;


int Filters::mask[25];

void Filters::linear_filters(BITMAP* buffer, const char* type)
{
	srand(time(NULL));
	int mask_sum = 0;
	for (int i = 0; i < 25; i++)
	{
		if (type == "Mean Filter")
			mask[i] = average_mask[i];
		if (type == "Horizontal Edges")
			mask[i] = horizontal_edges_mask[i];
		if (type == "Vertical Edges")
			mask[i] = vertical_edges_mask[i];
		if (type == "Random")
			mask[i] = user_mask[i];

		mask_sum += mask[i];
	}

	int sum_r;
	const int margin = 5 - 1 / 2;
	for (int i = x0 + margin; i < x_margin; i++)
	{
		for (int j = y0 + margin; j < y_margin; j++)
		{
			sum_r = 0;
			if (getr(getpixel(buffer, i, j)) > getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) - power
				&& getr(getpixel(buffer, i, j)) < getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) + power
				&& get_cursor_position_x() >= 100 && get_cursor_position_x() < 612
				&& get_cursor_position_y() >= 160 && get_cursor_position_y() < 672)
			{
				for (int k = 0; k < 5; k++)
					for (int l = 0; l < 5; l++)
					{
						sum_r += mask[k * 5 + l] * getr(getpixel(buffer, i + k - margin, j + l - margin));
					}
				if (mask_sum > 0)
					sum_r /= mask_sum;

				if (sum_r > 255) sum_r = 255;
				else if (sum_r < 0) sum_r = 0;
			}
			else
				sum_r = getr(getpixel(buffer, i, j));


			putpixel(buffer, i + 520, j, makecol(sum_r, sum_r, sum_r));
		}
	}
}

void Filters::negative_filter(BITMAP* buffer)
{
	int color;
	for (int i = x0; i < x_margin; i++)
		for (int j = y0; j < y_margin; j++)
		{
			if (getr(getpixel(buffer, i, j)) > getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) - power
				&& getr(getpixel(buffer, i, j)) < getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) + power
				&& get_cursor_position_x() >= 100 && get_cursor_position_x() < 612
				&& get_cursor_position_y() >= 160 && get_cursor_position_y() < 672)
			{
				color = 255 - getr(getpixel(buffer, i, j));
				putpixel(buffer, i + 520, j, makecol(color, color, color));
			}
			else
			{
				color = getr(getpixel(buffer, i, j));
				putpixel(buffer, i + 520, j, makecol(color, color, color));
			}
		}
}

void Filters::minimal_filter(BITMAP* buffer)
{
	const int margin = 5 - 1 / 2;
	for (int i = x0 + margin; i < x_margin; i++)
	{
		for (int j = y0 + margin; j < y_margin; j++)
		{
			if (getr(getpixel(buffer, i, j)) > getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) - power
				&& getr(getpixel(buffer, i, j)) < getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) + power
				&& get_cursor_position_x() >= 100 && get_cursor_position_x() < 612
				&& get_cursor_position_y() >= 160 && get_cursor_position_y() < 672)
			{
				int collorMin = 255;
				for (int k = 0; k < 5; k++)
					for (int l = 0; l < 5; l++)
					{
						if (collorMin > getr(getpixel(buffer, i + k - margin, j + l - margin)))
							collorMin = getr(getpixel(buffer, i + k - margin, j + l - margin));
					}
				putpixel(buffer, i + 520, j, makecol(collorMin, collorMin, collorMin));
			}
			else
			{
				int col = getr(getpixel(buffer, i, j));
				putpixel(buffer, i + 520, j, makecol(col, col, col));
			}
		}
	}
}

void Filters::maxinum_filter(BITMAP* buffer)
{
	const int margin = 5 - 1 / 2;
	for (int i = x0 + margin; i < x_margin; i++)
	{
		for (int j = y0 + margin; j < y_margin; j++)
		{
			if (getr(getpixel(buffer, i, j)) > getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) - power
				&& getr(getpixel(buffer, i, j)) < getr(getpixel(buffer, get_cursor_position_x(), get_cursor_position_y())) + power
				&& get_cursor_position_x() >= 100 && get_cursor_position_x() < 612
				&& get_cursor_position_y() >= 160 && get_cursor_position_y() < 672)
			{
				int collorMin = 0;
				for (int k = 0; k < 5; k++)
					for (int l = 0; l < 5; l++)
					{
						if (collorMin < getr(getpixel(buffer, i + k - margin, j + l - margin)))
							collorMin = getr(getpixel(buffer, i + k - margin, j + l - margin));
					}
				putpixel(buffer, i + 520, j, makecol(collorMin, collorMin, collorMin));
			}
			else
			{
				int col = getr(getpixel(buffer, i, j));
				putpixel(buffer, i + 520, j, makecol(col, col, col));
			}
		}
	}
}


void Filters::set_cursor_position_x(int x)
{
	cursor_position_x = x;
}

void Filters::set_cursor_position_y(int y)
{
	cursor_position_y = y;
}

int Filters::get_cursor_position_x()
{
	return cursor_position_x;
}

int Filters::get_cursor_position_y()
{
	return cursor_position_y;
}

const char* Filters::to_string_cursor_position()
{
	std::string s = std::to_string(get_cursor_position_x());
	s += " ";
	s += std::to_string(get_cursor_position_y());
	return s.c_str();
}

const char* Filters::to_string_power()
{
	std::string s = std::to_string(get_power());
	return s.c_str();
}

void Filters::set_power(int p)
{
	power = p;
}

int Filters::get_power()
{
	return power;
}


int Filters::get_mask(int i)
{
	return mask[i];
}


Filters::~Filters()
{
}
