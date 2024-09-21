#include <stdio.h>

int main(void) {
	int n;
	int a;
	int ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if  (a % 2 == 0 &&
			(a % 3 != 0 && a % 5 != 0)) {
			ans = 0;
		}
	}
	printf(ans ? "APPROVED" : "DENIED");

	return 0;
}