#include <stdio.h>


int main(void) {
    char bm[100][101];
    int d, n, i, j, x, y, k, l;

    scanf("%d", &d);
    while (d--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            for (j = 1; j <= n; j++) {
                if (j != n) {
                    bm[i][j] = ' ';
                }
                else {
                    bm[i][j] = '\0';
                }
            }
        }
        for (i = n - 1; i >= 0; i--) {
            bm[i][0] = '#';
        }
        x = 0;
        y = 0;
        k = 1;
        for (l = n - 1; l > 0; l-=2, k*=-1) {
            for (i = 0; i < l; i++) {
                x += k;
                bm[y][x] = '#';
            }
            if (l > 1) {
                for (i = 0; i < l; i++) {
                    y += k;
                    bm[y][x] = '#';
                }
            }
        }

        for (i = 0; i < n; i++) {
            puts(bm[i]);
        }
        if (d) puts("");
    }
    return 0;
}