#include <ctime>
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
	0, 0, -1, 0, 0,
	0, 0, -1, 0, 0,
	0, 0, 2, 0, 0,
	0, 0, 0, 0, 0,
	0, 0, 0, 0, 0,
};

int Filters::vertical_edges_mask[] = {
	0, 0, -1, 0, 0,
	0, 0, -1, 0, 0,
	0, 0, 4, 0, 0,
	0, 0, -1, 0, 0,
	0, 0, -1, 0, 0,
};

int Filters::random_mask[25];

void Filters::fill_array()
{
	for (int i = 0; i < 25; i++)
		random_mask[i] = std::rand() % 10 - 2;
}

int Filters::get_mask()
{
	return *mask;
}

int Filters::mask[25];

void Filters::linear_filters(BITMAP* buffer, const char* type)
{
	srand(time(NULL));

	for (int i = 0; i < 25; i++)
	{
		if (type == "Mean Filter")
			mask[i] = average_mask[i];
		if (type == "Horizontal Edges")
			mask[i] = horizontal_edges_mask[i];
		if (type == "Vertical Edges")
			mask[i] = vertical_edges_mask[i];
		if (type == "Random")
			mask[i] = random_mask[i];
	}

	int sum_r, sum_g, sum_b;
	const int margin = 5 - 1 / 2;
	for (int i = x0 + margin; i < x_margin; i++)
	{
		for (int j = y0 + margin; j < y_margin; j++)
		{
			sum_r = 0;
			sum_g = 0;
			sum_b = 0;

			if (255 - getr(getpixel(buffer, i, j)) <= POWER)
			{
				for (int k = 0; k < 5; k++)
					for (int l = 0; l < 5; l++)
					{
						sum_r += mask[k * 5 + l] * getr(getpixel(buffer, i + k - margin, j + l - margin));
						sum_g += mask[k * 5 + l] * getg(getpixel(buffer, i + k - margin, j + l - margin));
						sum_b += mask[k * 5 + l] * getb(getpixel(buffer, i + k - margin, j + l - margin));
					}


				sum_r /= sizeof(mask) / sizeof(int);
				sum_g /= sizeof(mask) / sizeof(int);
				sum_b /= sizeof(mask) / sizeof(int);

				if (sum_r > 255) sum_r = 255;
				else if (sum_r < 0) sum_r = 0;
				if (sum_g > 255) sum_g = 255;
				else if (sum_g < 0) sum_g = 0;
				if (sum_b > 255) sum_b = 255;
				else if (sum_b < 0) sum_b = 0;
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
			if (255 - getr(getpixel(buffer, i, j)) <= POWER)
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
			if (255 - getr(getpixel(buffer, i, j)) <= POWER)
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
			if (255 - getr(getpixel(buffer, i, j)) <= POWER)
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


Filters::~Filters()
{
}
