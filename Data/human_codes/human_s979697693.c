#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int mimorinn(const void* x, const void* y) {
	int64_t a = *(const int64_t*)x, b = *(const int64_t*)y;
	return a < b ? -1 : a > b;
}

int N;
int64_t a[64];

int64_t sousa(void) {
	int64_t no, yes;
	int64_t limit;
	int i;
	qsort(a, N, sizeof(*a), mimorinn);
	if (a[N - 1] <= N - 1) return 0;
	no = 0;
	yes = a[N - 1] / N + 1;
	while (no + 1 < yes) {
		int64_t m = no + (yes - no) / 2;
		if (a[N - 2] + m <= a[N - 1] - N * m) no = m; else yes = m;
	}
	/* limit = (a[N - 1] - (N - 1) + (N - 1)) / N; */
	limit = a[N - 1] / N;
	if (yes > limit) yes = limit;
	for (i = 0; i < N - 1; i++) a[i] += yes;
	a[N - 1] -= N * yes;
	qsort(a, N, sizeof(*a), mimorinn);
	return yes;
}

int main(void) {
	int i;
	int64_t miyukiti = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%" SCNd64, &a[i]) != 1) return 1;
	}
	qsort(a, N, sizeof(*a), mimorinn);
	while (a[0] + N < a[N - 1]) {
		int64_t delta = sousa();
		if (delta <= 0) {
			printf("%" PRId64 "\n", miyukiti);
			return 0;
		}
		miyukiti += delta;
	}
	if (a[0] > N) {
		int64_t delta = a[0] - N;
		miyukiti += delta * N;
		for (i = 0; i < N; i++) a[i] -= delta;
	}
	for (;;) {
		int64_t delta = sousa();
		if (delta <= 0) {
			printf("%" PRId64 "\n", miyukiti);
			return 0;
		}
		miyukiti += delta;
	}
	return 0;
}
