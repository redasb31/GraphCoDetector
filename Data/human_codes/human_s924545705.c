#include<stdio.h>

int main(void){

    long int A,B,K;

    scanf("%ld %ld %ld",&A,&B,&K);

    if(K <= A){
        A -= K;
    }else{
        B -= K-A;
        A = 0;
    }

    printf("%ld %ld\n",A,B);
    return 0;
}
