#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void) {
	long int n,k,max=0,temp=0;
	long int a[200010];

	scanf("%ld %ld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%ld", &a[i]);
		temp += a[i];
		if (i - k > 0) {
			temp -= a[i-k];
			if (max <= temp) max = temp;
		}
	}
	printf("%.10Lf", (long double)(max + k) / 2);
	return 0;
}
