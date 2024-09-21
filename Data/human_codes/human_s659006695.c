// AOJ 2237: The Castle
// 2017.12.9

#include <stdio.h>
#include <string.h>

double p[16][16];
double dp[65536][16];
 
int main()
{
    int m, n, i, j, k, l, b;
	double t, a, pro;

	scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++) for (j = 0; j < n; j++) scanf("%lf", &p[i][j]);

    for (i = (1 << m) - 1; i >= 0; i--) {
        for (j = n-1; j >= 0; j--) {
            t = 0;
            for (b = 1, k = 0; k < m; k++, b <<= 1) if (!(i & b)) {
				pro = 1, a = 0;
                for (l = j; l < n; l++) {
                    a += pro * (1.0 - p[k][l]) * dp[i | b][l];
                    pro *= p[k][l];
                }
                a += pro;
				if (a > t) t = a;
            }
            dp[i][j] = t;
        }
    }
    printf("%.12lf\n",dp[0][0]);
    return 0;
}