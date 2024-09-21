#include <stdio.h>          // printf(), scanf()
#include <stdbool.h>

typedef struct rect_tbl
{
	double x1, y1;
	double x2, y2;
} rect_t;

bool
isoverlap(rect_t a, rect_t b)
{
	if (a.x1 > b.x2 || a.x2 < b.x1)
		return false;

	if (a.y1 > b.y2 || a.y2 < b.y1)
		return false;

	return true;
}

int
main(int argc, char **argv)
{
	rect_t a, b;

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a.x1, &a.y1, &a.x2, &a.y2, &b.x1, &b.y1, &b.x2, &b.y2) != EOF)
		printf("%s\n", isoverlap(a, b) ? "YES" : "NO");

	return 0;
}