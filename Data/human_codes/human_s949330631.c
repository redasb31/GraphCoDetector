#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
    int N;
    scanf("%d",&N);
    int A[N+1];
    int B[N+1];
    int C[N];
  memset(A, 0, N+1*sizeof(*A));
  memset(B, 0, N+1*sizeof(*B));
  memset(C, 0, N*sizeof(*C));
    for (int i=1;i<=N;i++){
        scanf("%d",&A[i]);
    }
    for (int i=1;i<=N;i++){
        scanf("%d",&B[i]);
    }
    for (int i=1;i<N;i++){
        scanf("%d",&C[i]);
    }
    int sum=0;
    for (int i=1;i<=N;i++){
        if (A[i]==A[i-1]+1){sum+=B[A[i]]+C[A[i-1]];}
        else sum+=B[A[i]];
    }
    printf("%d",sum);



return EXIT_SUCCESS;
}
