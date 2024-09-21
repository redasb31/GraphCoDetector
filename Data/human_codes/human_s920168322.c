#include<stdio.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
#define S(type,x) fscanf(stdin,"%"#type,&x)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
int dp[850][850];
int main() {
	int t[50],
		i,j,k,n;
	for (i = 0; i < 850; i++)for (j = 0; j < 850; j++)dp[i][j] = 1 << 20;
	dp[0][0] = 0;
	S(d, n);
	for (i = 0; i < n; i++)S(d, t[i]);
	for (i = 0; i<n; i++)
		for (j = 849; j >= 0; j--)
			for (k = 849; k >= 0; k--) {
				dp[j][k] += t[i];
				if (j >= t[i]) dp[j][k] = MIN(dp[j][k], dp[j - t[i]][k]);
				if (k >= t[i]) dp[j][k] = MIN(dp[j][k], dp[j][k - t[i]]);
			}
	int a = 1 << 20;
	for (i = 0; i < 850; i++)
		for (j = 0; j < 850; j++) {
			int x = MAX(i, j);
			x = MAX(x, dp[i][j]);
			a = MIN(a,x);
		}
	P(d, a);
	return 0;
}