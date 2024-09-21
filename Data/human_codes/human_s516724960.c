#include <stdio.h>
#include <math.h>

int N;
int T[114514], A[114514];
int Q;
int L[114514], R[114514];

int count[114514][8];

int main(void) {
	int i, j;
	if (scanf("%d", &N) != 1) return 1;
	for(i = 1; i <= N; i++) {
		if (scanf("%d%d", &T[i], &A[i]) != 2) return 1;
	}
	T[0] = 0; A[0] = 0;
	T[N + 1] = 1111111111; A[N + 1] = 0;
	if (scanf("%d", &Q) != 1) return 1;
	for (i = 0; i < Q; i++) {
		if (scanf("%d%d", &L[i], &R[i]) != 2) return 1;
	}
	count[0][0] = 1;
	for (i = 1; i <= N + 1; i++) {
		for (j = 0; j <= 7; j++) {
			count[i][j] = count[i - 1][j];
		}
		count[i][A[i]]++;
	}
	for (i = 0; i < Q; i++) {
		int lower = 0, left = N + 1, right = 0, upper = N + 1;
		double yosinagasayuri = 1e+9;
		while (lower + 1 < left) {
			int mid = lower + (left - lower) / 2;
			if (T[mid] < L[i]) lower = mid; else left = mid;
		}
		while (right + 1 < upper) {
			int mid = right + (upper - right)/ 2;
			if (R[i] < T[mid]) upper = mid; else right = mid;
		}
		for (j = 0; j <= 7; j++) {
			int kazu = count[right][j] - count[lower][j];
			yosinagasayuri *= pow(1.0 - j * 0.1, kazu);
		}
		printf("%.15f\n", yosinagasayuri);
	}
	return 0;
}

