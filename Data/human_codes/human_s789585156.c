#include <stdio.h>
#include <math.h>

#define INF 999999999
#define EPS 1e-10

/* solve a1 * x + b1 <= a2 * x + b2 */
void solve_futousiki_merge(double* min, double* max, double a1, double b1, double a2, double b2) {
	double min2, max2;
	/* (a1 - a2) * x <= b2 - b1 */
	double a = a1 - a2, b = b2 - b1;
	if (fabs(a) < EPS) {
		if (-EPS < b) {
			min2 = -INF;
			max2 = INF;
		} else {
			min2 = INF;
			max2 = -INF;
		}
	} else if (a > 0) {
		min2 = -INF;
		max2 = b / a;
	} else {
		min2 = b / a;
		max2 = INF;
	}
	if (*min < min2) *min = min2;
	if (max2 < *max) *max = max2;
}

int N;
int x[114514], y[114514];
char d[114514];

int rmin, rmax, lmin, lmax, xfmin, xfmax, umin, umax, dmin, dmax, yfmin, yfmax;

int x_valid[3], y_valid[3];

/* f(x) = a * x + b */
double xmin_a[3], xmin_b[3], xmax_a[3], xmax_b[3];
double ymin_a[3], ymin_b[3], ymax_a[3], ymax_b[3];

/* 定義域 */
double xmin_min[3], xmin_max[3], xmax_min[3], xmax_max[3];
double ymin_min[3], ymin_max[3], ymax_min[3], ymax_max[3];

int main(void) {
	int i, j, k, l;
	double answer = (double)INF * INF;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		char asumisu[4];
		if (scanf("%d%d%3s", &x[i], &y[i], asumisu) != 3) return 1;
		d[i] = asumisu[0];
	}

	/* それぞれのかたまりの範囲を求める */
	rmin = lmin = umin = dmin = xfmin = yfmin = INF;
	rmax = lmax = umax = dmax = xfmax = yfmax = -INF;
	for (i = 0; i < N; i++) {
		switch (d[i]) {
			case 'R':
				if (rmin > x[i]) rmin = x[i];
				if (rmax < x[i]) rmax = x[i];
				x_valid[2] = 1;
				break;
			case 'L':
				if (lmin > x[i]) lmin = x[i];
				if (lmax < x[i]) lmax = x[i];
				x_valid[0] = 1;
				break;
			case 'U':
				if (umin > y[i]) umin = y[i];
				if (umax < y[i]) umax = y[i];
				y_valid[2] = 1;
				break;
			case 'D':
				if (dmin > y[i]) dmin = y[i];
				if (dmax < y[i]) dmax = y[i];
				y_valid[0] = 1;
				break;
		}
		switch (d[i]) {
			case 'R': case 'L':
				if (yfmin > y[i]) yfmin = y[i];
				if (yfmax < y[i]) yfmax = y[i];
				y_valid[1] = 1;
				break;
			case 'U': case 'D':
				if (xfmin > x[i]) xfmin = x[i];
				if (xfmax < x[i]) xfmax = x[i];
				x_valid[1] = 1;
				break;
		}
	}

	/* かたまりの情報をもとに、採用された時のパラメータを求める */
	xmin_a[0] = -1; xmin_b[0] = lmin;
	xmin_a[1] =  0; xmin_b[1] = xfmin;
	xmin_a[2] =  1; xmin_b[2] = rmin;

	xmax_a[0] = -1; xmax_b[0] = lmax;
	xmax_a[1] =  0; xmax_b[1] = xfmax;
	xmax_a[2] =  1; xmax_b[2] = rmax;

	ymin_a[0] = -1; ymin_b[0] = dmin;
	ymin_a[1] =  0; ymin_b[1] = yfmin;
	ymin_a[2] =  1; ymin_b[2] = umin;

	ymax_a[0] = -1; ymax_b[0] = dmax;
	ymax_a[1] =  0; ymax_b[1] = yfmax;
	ymax_a[2] =  1; ymax_b[2] = umax;

	/* それらのパラメータが有効な範囲を求める */
	for (i = 0; i < 3; i++) {
		xmin_min[i] = xmax_min[i] = ymin_min[i] = ymax_min[i] = -INF;
		xmin_max[i] = xmax_max[i] = ymin_max[i] = ymax_max[i] = INF;
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			/* minについては他以上に小さい、maxについては他以上に大きい */
			if (i != j) {
				if (x_valid[i] && x_valid[j]) {
					solve_futousiki_merge(&xmin_min[i], &xmin_max[i], xmin_a[i], xmin_b[i], xmin_a[j], xmin_b[j]);
					solve_futousiki_merge(&xmax_min[i], &xmax_max[i], xmax_a[j], xmax_b[j], xmax_a[i], xmax_b[i]);
				}
				if (y_valid[i] && y_valid[j]) {
					solve_futousiki_merge(&ymin_min[i], &ymin_max[i], ymin_a[i], ymin_b[i], ymin_a[j], ymin_b[j]);
					solve_futousiki_merge(&ymax_min[i], &ymax_max[i], ymax_a[j], ymax_b[j], ymax_a[i], ymax_b[i]);
				}
			}
		}
	}

#ifdef DEBUG_PRINT
	/* デバッグ */
	puts("x");
	for (i = 0; i < 3; i++) {
		printf("%d %g %g %g %g\n", x_valid[i], xmin_min[i], xmin_max[i], xmax_min[i], xmax_max[i]);
	}
	puts("y");
	for (i = 0; i < 3; i++) {
		printf("%d %g %g %g %g\n", y_valid[i], ymin_min[i], ymin_max[i], ymax_min[i], ymax_max[i]);
	}
	puts("---");
#endif

	/* どの範囲を使うかを全探索する */
	for (i = 0; i < 3; i++) {
		if (!x_valid[i]) continue;
		for (j = 0; j < 3; j++) {
			double xa = xmax_a[j] - xmin_a[i], xb = xmax_b[j] - xmin_b[i];
			if (!x_valid[j]) continue;
			for (k = 0; k < 3; k++) {
				if (!y_valid[k]) continue;
				for (l = 0; l < 3; l++) {
					double ya = ymax_a[l] - ymin_a[k], yb = ymax_b[l] - ymin_b[k];
					/* 関数の係数と定義域を決定する */
					double a = xa * ya;
					double b = xa * yb + ya * xb;
					double c = xb * yb;
					double curmin = (double)INF * INF;
					double okmin = 0, okmax = INF;
					if (!y_valid[l]) continue;
					if (okmin < xmin_min[i]) okmin = xmin_min[i];
					if (xmin_max[i] < okmax) okmax = xmin_max[i];
					if (okmin < xmax_min[j]) okmin = xmax_min[j];
					if (xmax_max[j] < okmax) okmax = xmax_max[j];
					if (okmin < ymin_min[k]) okmin = ymin_min[k];
					if (ymin_max[k] < okmax) okmax = ymin_max[k];
					if (okmin < ymax_min[l]) okmin = ymax_min[l];
					if (ymax_max[l] < okmax) okmax = ymax_max[l];
#ifdef DEBUG_PRINT
					printf("%d %d %d %d | %g %g | %g %g %g\n", i, j, k, l, okmin, okmax, a, b, c);
#endif
					if (okmin > okmax + EPS) continue;
					/* それに基づいて最小値を決定する */
					if (fabs(a) < EPS) {
						/* 関数は直線 */
						if (b >= 0) {
							/* 右肩上がりまたはx軸に並行なので、左端が最小 */
							curmin = b * okmin + c;
						} else {
							/* 左肩上がりなので、右端が最小 */
							curmin = b * okmax + c;
						}
					} else {
						/* 関数は放物線 */
						double kyokusyo = -b / (2.0 * a);
						double candidate;
#ifdef DEBUG_PRINT
						printf("kyokusyo = %g\n", kyokusyo);
#endif
						/* 左端 */
						curmin = a * okmin * okmin + b * okmin + c;
#ifdef DEBUG_PRINT
						printf("left %g\n", curmin);
#endif
						/* 右端 */
						candidate = a * okmax * okmax + b * okmax + c;
#ifdef DEBUG_PRINT
						printf("right %g\n", candidate);
#endif
						if (candidate < curmin) curmin = candidate;
						/* 極大/極小の場所 (極大なら最小にならないけど、条件分岐を省略) */
						if (okmin <= kyokusyo + EPS && kyokusyo <= okmax + EPS) {
							candidate = a * kyokusyo * kyokusyo + b * kyokusyo + c;
#ifdef DEBUG_PRINT
							printf("center %g\n", candidate);
#endif
							if (candidate < curmin) curmin = candidate;
						}
					}
#ifdef DEBUG_PRINT
					printf("curmin = %g\n", curmin);
#endif
					if (curmin < answer) answer = curmin;
				}
			}
		}
	}

	printf("%.15f\n", answer);
	return 0;
}

/*

縮まる

RRRRRR->
         <-LLLLL

変わらない

     RRRRRR->
    <-LLLLL

広がる

      RRRRRR->
   <-LLLLL

これに加えて、位置が変わらないかたまりもある。
そのため、最小値・最大値それぞれについて、どれが採用されるかを計算する。

*/
