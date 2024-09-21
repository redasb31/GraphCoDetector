#include <stdio.h>
#include <stdlib.h>

int arr[200000];

void insert(int n, int x) {
	int lo = 0, hi = n-1;
	while (lo < hi) {
		int mi = (lo+hi)/2;
		if (x < arr[mi]) hi = mi;
		else lo = mi+1;
	}
	while (lo <= n) {
		int t = x;
		x = arr[lo];
		arr[lo] = t;
		lo++;
	}
}

int main(void) {
	int q;
	scanf("%d", &q);

	int n = 0;
	long long int d = 0;
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			insert(n++, a);
			d += b;
		} else {
			long long int s = d;
			int x = arr[(n-1)/2];
			for (int i = 0; i < n; i++) {
				s += abs(x-arr[i]);
			}
			printf("%d %lld\n", x, s);
		}
	}
}
