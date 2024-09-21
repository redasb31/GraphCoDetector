#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 400

void coloring_replace(int w, int h, int orig, int new, int col[MAX_SIZE][MAX_SIZE])
{
    int x, y;

    if (orig == new) {return;}

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (col[y][x] == -1) {break;}
            if (col[y][x] == orig) {col[y][x] = new;}
        }
    }

    return;
}

int coloring(int w, int h, char s_inv[MAX_SIZE][MAX_SIZE + 1], int col[MAX_SIZE][MAX_SIZE])
{
    int x, y;
    int count = 0;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            col[y][x] = -1;
        }
    }

    col[0][0] = count; // (0, 0)は色番号0
    count++;
    y = 0;
    for (x = 1; x < w; x++) {
        if (s_inv[y][x - 1] == s_inv[y][x]) {
            col[y][x] = col[y][x - 1];
        } else {
            col[y][x] = count;
            count++;
        }
    }
    for (y = 1; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (s_inv[y - 1][x] == s_inv[y][x]) {
                col[y][x] = col[y - 1][x];
                if (x > 0 && s_inv[y][x - 1] == s_inv[y][x] && col[y][x - 1] != col[y][x]) {
                    coloring_replace(w, h, col[y][x - 1], col[y][x], col); //同じ色にする
                }
            } else if (x > 0 && s_inv[y][x - 1] == s_inv[y][x]) {
                col[y][x] = col[y][x - 1];
            } else {
                col[y][x] = count;
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    int h, w;
    int x, y;
    char s[MAX_SIZE][MAX_SIZE + 1];
    char s_inv[MAX_SIZE][MAX_SIZE + 1];
    int col[MAX_SIZE][MAX_SIZE];
    int col_b[MAX_SIZE * MAX_SIZE], col_w[MAX_SIZE * MAX_SIZE];
    long long ans;
    int i;
    int n_color;

    scanf("%d %d", &h, &w);

    for (i = 0; i < h; i++) {
        scanf("%s", s[i]);
    }

    // x + yが偶数な点のみ反転したマップを作る
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if ((x + y) % 2 == 0) {
                s_inv[y][x] = (s[y][x] == '#')?'.':'#';
            } else {
                s_inv[y][x] = s[y][x];
            }
        }
        s_inv[y][w] = 0;
    }

    // 反転マップを塗分ける
    n_color = coloring(w, h, s_inv, col);

    for (i = 0; i < n_color; i++) {
        col_w[i] = 0;
        col_b[i] = 0;
    }

    // オリジナルマップの黒/白を塗分けた色別にカウントする
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (s[y][x] == '#') {
                col_b[col[y][x]]++;
            } else {
                col_w[col[y][x]]++;
            }
        }
    }
    
    ans = 0;
    for (i = 0; i < n_color; i++) {
        ans += col_w[i] * col_b[i];
    }

    printf("%lld\n", ans);
    return 0;
}
