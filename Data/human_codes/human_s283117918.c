#include <stdio.h>
#include <stdlib.h>
#define scanf(a, b) (fflush(0), scanf(a,b))
int main(void) {
	int r;
	scanf("%d", &r);
	printf("%d", r * r);
	return EXIT_SUCCESS;
}