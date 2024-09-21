#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626
#define INF 1e10

#define sq(x) ((x) * (x))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(void) {
	int i, j, k, l;
	int n, vega, altair;

	while (scanf("%d %d %d", &n, &vega, &altair), n) {
		int x[100], y[100], a[100], r[100];
		double xx[100][5], yy[100][5];
		double d[100][100];

		for (i = 0; i < n; i++)
			scanf("%d %d %d %d", x + i, y + i, a + i, r + i);
		for (i = 0; i < n; i++)
			for (j = 0; j < 5; j++) {
				const double theta = (90. + 72. * j + a[i]) * PI / 180.;
				xx[i][j] = r[i] * cos(theta) + x[i];
				yy[i][j] = r[i] * sin(theta) + y[i];
			}

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = i == j ? 0 : INF;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++) {
				double min = INF;
				for (k = 0; k < 5; k++)
					for (l = 0; l < 5; l++)
						min = min(min, sqrt(sq(xx[i][k] - xx[j][l]) + sq(yy[i][k] - yy[j][l])));
				d[i][j] = d[j][i] = min;
			}

		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		printf("%.20f\n", d[vega - 1][altair - 1]);
	}

	return 0;
}