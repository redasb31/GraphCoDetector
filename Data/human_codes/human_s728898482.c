#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 1299709
int main() {
	int i, j, *p,cnt=0,n;
	p = (int*)calloc(N + 1, sizeof(int));
	for (i = 2; i <= (int)sqrt((double)N); ++i) if (!*(p + i)) for (j = i*i; j <= N; j += i) *(p + j) = 1;
	for (; ~fscanf(stdin, "%d", &n),n!=0;fprintf(stdout, "%d\n", cnt)) {
		cnt = 0;
		if (!*(p + n)) continue;
		while (!*(p)) {
			if (!*(p + n))break;
			n--;
		}
		for (i = n+1,cnt=1;*(p + i); i++) cnt++;
	}
	free(p);
	return 0;
}