#include <stdio.h>

int main(){
    int d,n;
    scanf("%d %d",&d,&n);

    if(d==0){
        if(n<100){printf("%d\n",n);}
        if(n==100){printf("101\n");}
    } else if(d==1){
        if(n<100){printf("%d\n",n*100);}
        if(n==100){printf("10001\n");}
    } else if(d==2){
        if(n<100){printf("%d\n",n*10000);}
        if(n==100){printf("1000001\n");}
    }

    return 0;
}