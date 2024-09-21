#include <stdio.h>
#include <stdlib.h>

int N;
int v = 0;
int w = 0; //1個の寿司が乗った皿がl枚
int x = 0; //2個の寿司が乗った皿がm枚
int y = 0; //3個の寿司が乗った皿がn枚

double pow2(double val) {
    return val * val;
}

// k: 0個の皿の数
// l: 1個の皿の数
// m: 2個の皿の数
// n: 3個の皿の数
// prob: ここのステートにたどり着くまで確率
// その状態から皿が全て0枚になるまでに必要な操作回数の期待値
double get_expectation(double ****DP, int k, int l, int m, int n) {
//double get_expectation(double ****DP, int k, int l, int m, int n, double prob) {
    if (DP[k][l][m][n] != -1) {
        return DP[k][l][m][n];
    }
    if (k == N)
        return 0;
    double dk = (double) k;
    double dl = (double) l;
    double dm = (double) m;
    double dn = (double) n;
    double dN = (double) N;
    //可能な遷移先
    // k + 1, l - 1 (l > 1)
    DP[k][l][m][n] = 1;
    if (l >= 1) {
        //DP[k][l][m][n] += get_expectation(DP, k + 1, l - 1, m, n, prob * dl / dN);
        DP[k][l][m][n] += get_expectation(DP, k + 1, l - 1, m, n) * dl / dN;
    }
    // l + 1, m - 1 (m > 1)
    if (m >= 1) {
        //DP[k][l][m][n] += get_expectation(DP, k, l + 1, m - 1, n, prob * dm / dN);
        DP[k][l][m][n] += get_expectation(DP, k, l + 1, m - 1, n) * dm / dN;
    }
    // m + 1, n - 1 (n > 1)
    if (n >= 1) {
        //DP[k][l][m][n] += get_expectation(DP, k, l, m + 1, n - 1, prob * dn / dN);
        DP[k][l][m][n] += get_expectation(DP, k, l, m + 1, n - 1) * dn / dN;
    }

    DP[k][l][m][n] /= (1 - dk /dN);
    //printf("%lf\n", DP[k][l][m][n]);
    return DP[k][l][m][n];
}

int main() {
    scanf("%d", &N);
    int *a = malloc((N + 1) * sizeof(int));
    double ****DP = malloc((N+1) * sizeof(double***));

    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1)
            w += 1;
        else if (a[i] == 2)
            x += 1;
        else
            y += 1;
    }

    for (int i = 0; i <= N; i++) {
        DP[i] = malloc((N+1) * sizeof(double**));
        for (int j = 0; j <= N; j++) {
            DP[i][j] = malloc((N+1) * sizeof(double*));
            for (int k = 0; k <= N; k++) {
                DP[i][j][k] = malloc((N+1) * sizeof(double));
                for (int l = 0; l <= N; l++) {
                    DP[i][j][k][l] = -1;
                }
            }
        }
    }

    //double ans = get_expectation(DP, v, w, x, y, 1.0);
    double ans = get_expectation(DP, v, w, x, y);

    printf("%1.10lf", ans);
    return 0;
}
