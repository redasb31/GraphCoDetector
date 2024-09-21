#include <stdio.h>

#define MAX_HEAL_COUNT 1000000000

int down[100000], heal[100000];
int dp[2][10000001], *next, *current;

int main(void) {
    int N, H, i, j, h, hp, min_count;

    scanf("%d%d", &N, &H);
    for (i = 0; i < N - 1; i++) {
        scanf("%d%d", &down[i], &heal[i]);
    }

    for (i = 0; i <= H; i++) {
        dp[0][i] = MAX_HEAL_COUNT;
    }
    dp[0][H] = 0;
    for (i = 0; i < N - 1; i++) {
        current = dp[i&1];
        next = dp[(i+1)&1];
        for (j = 1; j <= H; j++) next[j] = MAX_HEAL_COUNT;
        for (j = 1; j <= H; j++) {
            if (current[j] == MAX_HEAL_COUNT) continue;
            for (h = 0;; h++) {
                hp = j+ h * heal[i];
                if (hp > H) hp = H;
                hp -= down[i];
                if (hp <= 0) continue;
                if (current[j] + h < next[hp]) {
                    next[hp] = current[j] + h;
                }
                if (hp + down[i] >= H) break;
            }
        }
    }
    for (i = 1, min_count = MAX_HEAL_COUNT;
         i <= H; i++) {
        if (next[i] < min_count) min_count = next[i];
    }
    printf("%d\n", min_count);
    return 0;
}