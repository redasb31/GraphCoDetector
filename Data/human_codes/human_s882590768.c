#include <stdio.h>
#include <stdlib.h>
int comp(const int *a,const int *b){
    return *a-*b;
}
int main(){
    int test,n,i,a[51],sum=0;
    scanf("%d %d",&test,&n);
    for(i=0;i<test;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,test,sizeof(int),comp);
    for(i=0;i<n;i++){
        sum+=a[--test];
    }
    printf("%d\n",sum);
    return 0;
}
