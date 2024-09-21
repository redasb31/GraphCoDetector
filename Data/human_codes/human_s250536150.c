#include <stdio.h>

int main()
{
    int i, j;

    int N;
    scanf("%d", &N);
    int a[N];
    for( i = 0; i < N; ++i )
        scanf("%d", &a[i]);
    int M;
    scanf("%d", &M);
    int b[M];
    long c[M];
    for( i = 0; i < M; ++i )
        scanf("%d", &b[i]);
    for( i = 0; i < M; ++i )
        scanf("%ld", &c[i]);

    long score[M];
    for( i = 0; i < M; ++i )
        score[i] = 0;
    for( i = 0; i < M; ++i )
        for( j = 0; j < N; ++j ){
            if( a[j] <= b[i] )
                score[i] += a[j];
            if( c[i] <= score[i] )
                break;
        }

    for( i = 0; i < M; ++i )
        if( c[i] <= score[i] )
            printf("Yes\n");
        else
            printf("No\n");

    return 0;
}