#include <stdio.h>
#include <string.h>

#define WIDTH 3001
#define HEIGHT 51

int dp[HEIGHT * WIDTH];

int main(void)
{
	int i, j, k;
	int n, m, s;
	while(scanf("%d%d%d", &n, &m, &s), n){
		n *= n;
		dp[0] = 1;
		for(i=1; i<WIDTH*HEIGHT; ++i)
			dp[i] = 0;

		for(i=1; i<=m; ++i){
			for(j=n; j>=0; --j){
				for(k=s; k>=0; --k){
					if(j && i <= k){
						dp[j*WIDTH + k] = (dp[j*WIDTH + k] + dp[(j-1)*WIDTH + k-i]) % 100000;
					}
				}
			}
		}

		printf("%d\n", dp[n*WIDTH + s]);
	}

	return 0;
}