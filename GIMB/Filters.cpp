#include "Filters.h"

Filters::Filters()
{
}

void Filters::average_filter(BITMAP* buffer)
{
	//int mask[25] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int mask[25] = {1,	1,	2	,1,	1,
1,	2	,4,	2,	1,
2,	4	,8	,4,	2,
1,	2,	4	,2	,1,
1,	1	,2,	1,	1};
	int sum_r, sum_g, sum_b;
	int margin = 5 - 1 / 2;
	for (int i = x0 + margin; i < x_margin; i++)
	{
		for (int j = y0 + margin; j < y_margin ; j++)
		{
			sum_r = 0;
			sum_g = 0;
			sum_b = 0;
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

			putpixel(buffer, i+520, j, makecol(sum_r, sum_r, sum_r));
		}
	}
}


Filters::~Filters()
{
}
