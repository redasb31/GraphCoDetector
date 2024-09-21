//c.c C-*3 or /2
#include<stdio.h>

int main(void){
    int n,eve=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;++i){
        scanf("%d",a+i);
    }

    for(int i=0;i<n;++i){
        while(a[i]%2==0){
            eve++;
            a[i] /= 2;
        }
    }

    printf("%d\n",eve);
    return 0;
}