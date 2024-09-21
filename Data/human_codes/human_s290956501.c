#include <stdio.h>

int check(int *b, int n)
{
    int i;

#if 0
    printf("[");
    for (i = 0; i < n; i++){
        printf("%d ", b[i]);
    }
    printf("]\n");
#endif    
    for (i = 0; i < n; i++){
        if (b[i] != i + 1){
            return (0);
        }
    }
    return (1);
}

int main(void)
{
    int N, n;
    int block[100000];
    int cnt;
    int i, j;
    
    while (1){
        scanf("%d", &N);
        if (N == 0){
            break;
        }

        
        for (i = 0; i < N; i++){
            scanf("%d", &block[i]);
        }
        
        cnt = 0;
        n = N;
        block[n] = 0;
        while (1){
            if (check(block, n) == 1){
                printf("%d\n", cnt);
                break;
            }
            cnt++;
            if (cnt > 10000){
                printf("-1\n");
                break;
            }
            for (n = 0; block[n] != 0; n++);
            block[n] = n;
            block[n + 1] = 0;
            for (i = 0; i < n; i++){
                block[i]--;
            }
            
            for (i = j = 0; i <= n; i++){
                if (block[i] != 0){
                    block[j] = block[i];
                    j++;
                }
            }
            block[j] = 0;
            n = j;
//            for (; j <= n; j++){
//                block[j] = 0;
//            }

        }
    }
    return (0);
}

        
        
