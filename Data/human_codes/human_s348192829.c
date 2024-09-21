#include <stdio.h>
#include <string.h>

#define INF (1 << 15)

int min(int a, int b)
{
    return (b > a ? a : b);
}

int main(void)
{
    int i, j, k;
    int n;
    int div[10001];
    static short dp[2][5001][2];
    
    scanf("%d", &n);
    
    for (i = 1; i <= n - 1; i++){
        scanf("%d", &div[i]);
    }
    
    for (i = 0; i < 2; i++){
        for (j = 0; j <= n / 2; j++){
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    
    for (i = 0; i <= n / 2; i++){
        for (j = 0; j <= n / 2; j++){
            if (i > 0){
                dp[i % 2][j][0] = dp[(i - 1) % 2][j][0];
                dp[i % 2][j][1] = dp[(i - 1) % 2][j][0] + div[i + j];
            }
            if (j > 0){
                dp[i % 2][j][0] = min(dp[i % 2][j][0], dp[i % 2][j - 1][1] + div[i + j]);
                dp[i % 2][j][1] = min(dp[i % 2][j][1], dp[i % 2][j - 1][1]);
            }
        }
    }
    
    printf("%d\n", min(dp[n % 2][n / 2][0], dp[n % 2][n / 2][1]));
    
    return (0);
}