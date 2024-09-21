#include <stdio.h>          // printf(), scanf()
#include <math.h>           // ceil()
#include <stdbool.h>

int
main(int argc, char **argv)
{
	                         //   1    2    3    4    5    6    7 x
	const int toll_t[7][7] = {{   0, 300, 500, 600, 700,1350,1650},  // 1x
	                          { 300,   0, 350, 450, 600,1150,1500},  // 2x
	                          { 500, 350,   0, 250, 400,1000,1350},  // 3x
	                          { 600, 450, 250,   0, 250, 850,1300},  // 4x
	                          { 700, 600, 400, 250,   0, 600,1150},  // 5x
	                          {1350,1150,1000, 850, 600,   0, 500},  // 6x
	                          {1650,1500,1350,1300,1150, 500,   0}}; // 7x

	                         // 1   2   3   4   5   6   7 x
	const int dist_t[7][7] = {{ 0,  6, 13, 18, 23, 43, 58},  // 1x
	                          { 6,  0,  7, 12, 17, 37, 52},  // 2x
	                          {13,  7,  0,  5, 10, 30, 45},  // 3x
	                          {18, 12,  5,  0,  5, 25, 40},  // 4x
	                          {23, 17, 10,  5,  0, 20, 35},  // 5x
	                          {43, 37, 30, 25, 20,  0, 15},  // 6x
	                          {58, 52, 45, 40, 35, 15,  0}}; // 7x

	const int time1 = 17 * 60 + 30;
	const int time2 = 19 * 60 + 30;

	while (true)
	{
		int d;
		scanf("%d", &d);
		if (d == 0)
			break;

		d--;
		int h, m;
		scanf("%d%d", &h, &m);
		int t_src = 60 * h + m;

		int a;
		scanf("%d", &a);
		a--;
		scanf("%d%d", &h, &m);
		int t_dest = 60 * h + m;

		int dist = dist_t[d][a];
		int toll;
		if (((time1 <= t_dest && t_dest <= time2) || (time1 <= t_src && t_src <= time2)) && dist <= 40)
		{
			double b = toll_t[d][a] / (2.0 * 50.0);
			toll = ceil(b) * 50;
		}
		else
			toll = toll_t[d][a];

		printf("%d\n", toll);
	}

	return 0;
}
