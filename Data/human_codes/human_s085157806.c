#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	long long i, X;
	scanf("%lld", &X);
	for (i=1LL;;i++) {
		if (X<=i*(i+1LL)/2LL) break;
	}
	printf("%lld\n", i);

	return 0;
}