#include<stdio.h>
int main()
{
    int i,n,k;
    scanf("%d%d",&n,&k);
    int ara[n];
    for(i=0;i<n;i++){
        scanf("%d",&ara[i]);
    }
    int count=0;
    for(i=0;i<n;i++){
        if(ara[i]>=k)
            count++;
    }
    printf("%d\n",count);

}
