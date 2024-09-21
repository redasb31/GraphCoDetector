#include<stdio.h>

int gcd(int a, int b) {
	if (a < b) return gcd(b, a);
	if (a%b == 0) return b;
	return gcd(b, a%b);
}

int main() {
	int i, j, n;
	int *a;
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1 ; j++) {
			if (a[j] > a[j + 1]) swap(a[j],a[j+1]);
		}
	}

	for (i = n; i >= 0; i--) {
		for (j = n; j >= 1; j--) {
			if (gcd(a[j], a[j - 1]) == 1) swap(a[j], a[j - 1]);
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d",a[i]);
		if (i != n) printf(" ");
		else printf("\n");
	}
}