#include <stdio.h>
#include <inttypes.h>

int H, W;
char S[3333][3333];

int O[3333][3333], I[3333][3333];

int main(void) {
	int i, j;
	uint64_t horieyui = 0;
	if (scanf("%d%d", &H, &W) != 2) return 1;
	for (i = 0; i < H; i++) {
		if (scanf("%3332s", S[i]) != 1) return 1;
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (S[i][j] == 'O') O[i][j]++;
			if (S[i][j] == 'I') I[i][j]++;
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 1; j < W; j++) {
			O[i][j] += O[i][j - 1];
		}
	}
	for (i = 1; i < H; i++) {
		for (j = 0; j < W; j++) {
			I[i][j] += I[i - 1][j];
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (S[i][j] == 'J') {
				horieyui += (uint64_t)(O[i][W - 1] - O[i][j]) * (I[H - 1][j] - I[i][j]);
			}
		}
	}
	printf("%" PRIu64 "\n", horieyui);
	return 0;
}

