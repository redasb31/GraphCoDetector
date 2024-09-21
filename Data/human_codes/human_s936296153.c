#include <stdio.h>

#define KI_MAX (1 << 18) /* 262144 */

int ki[KI_MAX * 2 - 1];

void ki_set(int idx, int value) {
	int pos = idx + (KI_MAX - 1);
	ki[pos] = value;
	do {
		int a, b;
		pos = (pos - 1) / 2;
		a = ki[pos * 2 + 1];
		b = ki[pos * 2 + 2];
		ki[pos] = a >= b ? a : b;
	} while (pos > 0);
}

int ki_get_i(int idx, int qs, int qe, int ss, int se) {
	if (qe <= ss || se <= qs) { /* 完全に外れている */
		return -114514;
	} else if (qs <= ss && se <= qe) { /* セグメントがクエリに完全に含まれる */
		return ki[idx];
	} else {
		int sm = ss + (se - ss) / 2;
		int left = ki_get_i(idx * 2 + 1, qs, qe, ss, sm);
		int right = ki_get_i(idx * 2 + 2, qs, qe, sm, se);
		return left >= right ? left : right;
	}
}

int ki_get(int qs, int qe) {
	return qs < qe ? ki_get_i(0, qs, qe, 0, KI_MAX) : -114514;
}

int main(void) {
	int N, Q;
	int i;
	if (scanf("%d%d", &N, &Q) != 2) return 1;
	for (i = 1; i <= N; i++) {
		int A;
		if (scanf("%d", &A) != 1) return 1;
		ki_set(i, A);
	}
	ki_set(N + 1, 1010101010);
	for (i = 0; i < Q; i++) {
		int T, hoge, fuga;
		if (scanf("%d%d%d", &T, &hoge, &fuga) != 3) return 1;
		switch(T) {
			case 1:
				ki_set(hoge, fuga);
				break;
			case 2:
				printf("%d\n", ki_get(hoge, fuga + 1));
				break;
			case 3:
				{
					int no = hoge - 1, yes = N + 1;
					while (no + 1 < yes) {
						int mid = no + (yes - no) / 2;
						if (ki_get(hoge, mid + 1) >= fuga) yes = mid; else no = mid;
					}
					printf("%d\n", yes);
				}
				break;
		}
	}
	return 0;
}
