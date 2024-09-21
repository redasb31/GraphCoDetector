#include <stdio.h>
#include <inttypes.h>

/* (a * b) <=> c */
int mulcmp(uint64_t a, uint64_t b, uint64_t c) {
	uint64_t ab;
	if (a != 0 && b != 0 && a > UINT64_MAX / b) return 1;
	ab = a * b;
	return ab < c ? -1 : ab > c;
}

uint64_t sumipe(uint64_t kugyu) {
	uint64_t yes = 1, no = kugyu;
	if (kugyu <= 1) return kugyu;
	while (yes + 1 < no) {
		uint64_t mid = yes + (no - yes) / 2;
		if (mulcmp(mid, mid, kugyu) <= 0) yes = mid; else no = mid;
	}
	return yes;
}

uint64_t solve(uint64_t A, uint64_t B) {
	uint64_t nyan = A * B - 1;
	uint64_t hoge, fuga, foo;
	if (A < B) {
		uint64_t t = A;
		A = B;
		B = t;
	}
	hoge = sumipe(nyan);
	fuga = nyan / (hoge + 1);
	if (nyan / hoge == fuga) fuga--;
	foo = hoge + fuga;
	if (B <= hoge && foo > 0) foo--;
	return foo;
}

int main(void) {
	int Q;
	uint64_t A[128], B[128];
	int i;
	if (scanf("%d", &Q) != 1) return 1;
	for (i = 0; i < Q; i++) {
		if (scanf("%" SCNu64 "%" SCNu64, &A[i], &B[i]) != 2) return 1;
	}
	for (i = 0; i < Q; i++) {
		printf("%" PRId64 "\n", solve(A[i], B[i]));
	}
	return 0;
}
