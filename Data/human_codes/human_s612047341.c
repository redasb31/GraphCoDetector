#include <stdio.h>

int main()
{
	int i, j, N, C, D[32][32], c[502][502];
	scanf("%d %d", &N, &C);
	for (i = 1; i <= C; i++) {
		for (j = 1; j <= C; j++) scanf("%d", &(D[i][j]));
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) scanf("%d", &(c[i][j]));
	}
	
	int count[3][31] = {};
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) count[(i+j)%3][c[i][j]]++;
	}
	
	int k, l, min = 1 << 30, tmp;
	for (i = 1; i <= C; i++) {
		for (j = 1; j <= C; j++) {
			if (j == i) continue;
			for (k = 1; k <= C; k++) {
				if (k == i || k == j) continue;
				for (l = 1, tmp = 0; l <= C; l++) tmp += D[l][i] * count[0][l] + D[l][j] * count[1][l] + D[l][k] * count[2][l];
				if (tmp < min) min = tmp;
			}
		}
	}
	
	printf("%d\n", min);
	fflush(stdout);
	return 0;
}