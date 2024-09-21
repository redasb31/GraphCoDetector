#include <stdio.h>

int main(void)
{
        int i,j,N,M,K,z,x=0;

        scanf("%d%d",&N,&M);

        int A[M];

        for(i=0;i<N;i++){
                scanf("%d",&K);
                for(j=0;j<K;j++){
                        scanf("%d",&z);
                        A[z]++;
                }

        }

        for(i=0;i<M;i++){
                if(A[i]==M)x++;
        }

        printf("%d\n",x);

        return 0;
}


~               