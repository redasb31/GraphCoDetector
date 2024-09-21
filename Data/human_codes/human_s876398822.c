#include <stdio.h>

typedef unsigned long long ull;

ull slime_combine(ull *a, size_t N) {
    ull sz[N][N], cost[N][N], tmp;
    size_t i, j, k, l;
    for (i = 0 ; i<N ; i++) {
        sz[i][i] = a[i];
        cost[i][i] = 0;
    }
    for (l = 1 ; l<N ; l++)
        for (i = 0, j = l ; j<N ; i++, j++) {
            cost[i][j] = cost[i+1][j] + a[i] + sz[i+1][j];
            sz[i][j] = a[i] + sz[i+1][j];
            for (k = i+1 ; k<j ; k++) {
                tmp = cost[i][k] + cost[k+1][j] + sz[i][k] + sz[k+1][j];
                if (tmp<cost[i][j]) cost[i][j] = tmp;
            }
        }
    return cost[0][N-1];
}

int main() {
    unsigned N;
    scanf("%u", &N);
    ull a[N];
    for (unsigned i = 0 ; i<N ; i++) scanf("%llu", a+i);
    printf("%llu", slime_combine(a, N));
    return 0;
}
