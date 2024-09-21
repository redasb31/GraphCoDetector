#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(void){
    int num;
    long *a_n,*an;
    long mod=0;
    scanf("%d",&num);
    a_n=(long *)malloc(sizeof(long)*num);
    int i;
    for(i=0;i<num;i++){
        scanf("%ld",&a_n[i]);
        mod+=a_n[i]-1;
    }
    printf("%ld",mod);
    return 0;

}