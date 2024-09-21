#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

int main(void){
    int N;
    scanf("%d",&N);

    int* H;
    NEW(H,N+1); //Hi→H[i]とする、添字範囲0~N
    for(int i=1;i<=N;i++){
        scanf("%d",&H[i]);
    }

    int count=0;
    int ans;

    for(int i=1;i<=N;i++){
        if(H[i]>=H[i+1]&&i!=N){ //右隣に移動できる時
            count+=1;
        }
        else if(H[i]<H[i+1]||i==N){
            if(ans<count){
                ans=count;
            }
            count=0;
        }
    }

    printf("%d\n",ans);

    return 0;
}