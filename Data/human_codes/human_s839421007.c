#include <stdio.h>

#include<limits.h>
/*競技プログラミングでよく使う関数とかテクニック*/
int INF = INT_MAX /10; //とりあえずめっちゃ大きい数字を用意しておくと便利

//aとbの中身を入れ替える。
void swap (int *a, int *b){
    int t = *a; *a = *b;*b = t;
}
//////////////////////////////////



int main(void){
    int N,M,i,x,tmp,r,TLCM,j,k,dif,a,Ntemp,Mtemp;
    int l=0;
    int difsum=0;
    int str[1000];
    int max=0,min=100;
    
    scanf("%d %d",&N,&M);
    Ntemp=N;
    Mtemp=M;
    
    for(i=0; i<N; i++){
        scanf("%d", &str[i]);
    }
    
    x=N*M;
    
    if(N<M)swap(&N,&M);
    
    r = N % M;
    while(r!=0){
        N = M;
        M = r;
        r = N % M;
    }
    
    TLCM=x/M;
    //printf("TLCM=%d\n",TLCM); debug
    
    a=TLCM/Mtemp;
    //printf("a=%d\n",a); debug
    
    for(k=0; k<a; k++){
        //printf("hello%d\n",k); debug
        for(j=0; j<Mtemp; j++){
            //printf("Mtemp=%d\n",Mtemp); debug
            if(str[l]>=max){
                max=str[l];
            }
            //printf("%d\n",max); debug
            if(str[l]<=min){
                min=str[l];
            }
            //printf("%d\n",min); debug
            dif=max-min;
            //printf("%d\n",dif); debug
            l++;
            if(l==Ntemp){
                l=0;
            }
        }
        difsum += max - min;
        max=-10000000;
        min=10000000;
    }
    
    
    printf("%d\n",difsum);
    
    return 0;
}

