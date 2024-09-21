#include<stdio.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
#define S(type,x) fscanf(stdin,"%"#type,&x)
int main() {
	int n, i, j, m;
	double dp[1001] = {};
	dp[0] = 1;
	S(d, n), S(d, m);
	for (i = 0; i < n; i++) {
		j = 1;
		while (i + j <= n&&j <= m)dp[i + j] += dp[i] / (n - i), j++;
	}
	P(.10lf, dp[n]);
	return 0;
}