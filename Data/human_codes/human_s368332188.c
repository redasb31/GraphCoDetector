#include <stdio.h>

int main(void) {
	int H, A, B;
	int i;
	int tomatu = 0;
	if (scanf("%d%d%d", &H, &A, &B) != 3) return 1;
	for (i = A; i <= B; i++) {
		if (H % i == 0) tomatu++;
	}
	printf("%d\n", tomatu);
	return 0;
}

