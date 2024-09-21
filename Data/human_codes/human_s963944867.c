#include <stdio.h>

int K, T, a[112];
int max;

int main() {
	scanf("%d%d", &K, &T);
	for (int i = 0; i < T; ++i) { scanf("%d", &a[i]); }

	if (T == 1) { printf("%d\n", a[0] - 1); }
	else {
		for (int i = 0; i < T; ++i) {
			if (i == 0) { max = a[i]; }
			else if (max < a[i]) { max = a[i]; }
		}
		if (max - (K - max) - 1 <= 0) { printf("0\n"); }
		else { printf("%d\n", max - (K - max) - 1); }
	}

	return 0;
}