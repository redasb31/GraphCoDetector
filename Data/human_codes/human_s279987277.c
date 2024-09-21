// AOJ 1226: Fishnet
// 2017.10.14 bal4u@uu

#include <stdio.h>
#include <math.h>

typedef struct { double x, y; } PP;
PP tbl[35][35];
double a[4][35];

void intersection(PP *p, PP *p1, PP *p2, PP *p3, PP *p4)
{
	double bo, ua;
	bo = (p4->y-p3->y)*(p2->x-p1->x)-(p4->x-p3->x)*(p2->y-p1->y);
	ua = (p4->x-p3->x)*(p1->y-p3->y)-(p4->y-p3->y)*(p1->x-p3->x);
	p->x = p1->x + ua/bo * (p2->x-p1->x);
	p->y = p1->y + ua/bo * (p2->y-p1->y);
}

double calc_area(PP *pp)
{
	int i;
	double s;
	for (s = 0, i = 0; i < 4; i++) s += (pp[i].x-pp[i+1].x) * (pp[i].y+pp[i+1].y);
	return fabs(s)/2;
}

int main()
{
	int n, i, j;
	double ans, s;
	PP t[5];

	while (scanf("%d", &n) && n > 0) {
		for (j = 0; j < 4; j++) for (i = 1; i <= n; i++) scanf("%lf", &a[j][i]);
		n++;
		tbl[0][0].x = 0, tbl[0][0].y = 0;
		for (i = 1; i < n; i++) tbl[i][0].x = a[0][i], tbl[i][0].y = 0;
		tbl[n][0].x = 1, tbl[n][0].y = 0;

		tbl[0][n].x = 0, tbl[0][n].y = 1;
		for (i = 1; i < n; i++) tbl[i][n].x = a[1][i], tbl[i][n].y = 1;
		tbl[n][n].x = 1, tbl[n][n].y = 1;

		for (j = 1; j < n; j++) tbl[0][j].x = 0, tbl[0][j].y = a[2][j];
		for (j = 1; j < n; j++) tbl[n][j].x = 1, tbl[n][j].y = a[3][j];

		for (j = 1; j < n; j++) for (i = 1; i < n; i++)
			intersection(&tbl[i][j], &tbl[i][0], &tbl[i][n], &tbl[0][j], &tbl[n][j]);

		ans = 0;
		for (j = 1; j <= n; j++) for (i = 1; i <= n; i++) {
			t[0] = t[4] = tbl[i-1][j-1], t[1] = tbl[i][j-1];
			t[2] = tbl[i][j], t[3] = tbl[i-1][j];
			if ((s = calc_area(t)) >= ans) ans = s;
		}

		printf("%.6lf\n", ans);
	}
    return 0;
}