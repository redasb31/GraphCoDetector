#include <stdio.h>

int main(void){
    int a = 0, b = 0, N = 0, flag = 0;
    int s[100] = {}, f[100] = {};
    scanf("%d %d", &a, &b); scanf("%d", &N);
    for(int w = 1; w <= N; w++){
        scanf("%d %d", &s[w], &f[w]);
        if( a > s[w] && a < f[w] ){ flag = 1; } else if( b > s[w] && b < f[w] ){ flag = 1; }
    }
    if( flag == 1 ){ printf("1\n"); } else { printf("0\n"); }
    return 0;
}
