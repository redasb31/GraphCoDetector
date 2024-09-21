#include <stdio.h>

#define N_MAX 100

int n, a, b, c, d[N_MAX];

int compare_int(const int *a, const int *b){
	return *b - *a;
}

int solve(void){
	int i;

	int mole = c;
	int deno = a;
	double ans = 0.0;

	i = 0;
	for(;;){
		double u = (double)mole / (double)deno;
		if (u > ans){
			ans = u;
		}
		if (i == n){
			return printf("%d\n", (int)ans);
		}
		mole += d[i];
		deno += b;
		i++;
	}
}

int main(void){
	int i;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	for(i = n; i--; ){
		scanf("%d", &d[i]);
	}
	qsort(d, n, sizeof(int), compare_int);
	solve();
	return 0;
}