#include <stdio.h>
#include <math.h>
#define GRAVITY (1.0)
#define EPSILON (0.00001)

int main(void) {
	int d; /* 目標距離 */
	int n; /* 障害物の個数 */
	int b; /* バウンド回数の上限 */
	int p[10]; /* 障害物の座標 */
	int h[10]; /* 障害物の高さ */
	double vmin;
	int i, j;

	/* 入力 */
	scanf("%d%d%d", &d, &n, &b);
	for (i = 0; i < n; i++) scanf("%d%d", p + i, h + i);

	/* 速さの最小値を探す */
	for (i = 1; i <= b + 1; i++) {
		double vx, vy, top, bottom, t, tb, vi;
		/* 二分探索 */
		top = 200.0; /* 最大値を仮定 */
		bottom = 0.0;
		while (top - bottom >= EPSILON) {
			vy = bottom + (top - bottom) / 2.0;
			tb = vy * 2.0 / GRAVITY; /* バウンド周期 (v = v0 - g * t で v = -v0 より) */
			vx = 1.0 * d / i / tb;
			/* 各障害物について衝突するか調べる */
			for (j = 0; j < n; j++) {
				t = p[j] / vx; /* 障害物のx座標に到達する時刻 */
				while (t >= tb) t -= tb;
				if (- 0.5 * GRAVITY * t * t + vy * t <= h[j]) break; /* 衝突 */
			}
			if (j < n) bottom = vy; /* 衝突した */
			else if (vy > vx) top = vy; /* 衝突しなかった */
			else bottom = vy;
			/* debug */
			/* printf("%.5f (%2d: %.5f %.5f) (%.5f - %.5f)\n", sqrt(vx * vx + vy * vy), i, vx, vy, bottom, top); */
		}
		/* 最小値をとる */
		vi = sqrt(vx * vx + vy * vy);
		if (i == 1 || vi < vmin) vmin = vi;
	}

	/* 出力 */
	printf("%.5f\n", vmin);

	return 0;
}