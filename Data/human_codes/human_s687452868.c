#include <stdio.h>

int main(void) {
	int N;
	int i;
	int asumikana = 0;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		int A;
		if (scanf("%d", &A) != 1) return 1;
		if (A % 2 == 0) asumikana++;
	}
	printf("%d\n", asumikana);
	return 0;
}

