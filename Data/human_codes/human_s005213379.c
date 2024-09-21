#include <stdio.h>

int main(void)
{
    int N;
    char S[100000];
    int i;
    int n;
    
    scanf("%d%s", &N, S);

    n = 0;
    for (i = 0; i < N - 1; i++){
        if (S[i] != S[i + 1]){
            n++;
            i++;
        }
    }
    
    printf("%d\n", n);
    
    return (0);
}

