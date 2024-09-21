#include <stdio.h>
int main(void){
    int n;
    int ans;
    int i;
    int num;
    scanf("%d",&n);
    for(ans=1;;ans++)
    {
        num=0;
        for(i=1;i<=ans;i++)
        {
            if(ans%i==0) num++;
            if(num>n) break;
        }
        if(num==n) break;
    }
    printf("%d\n",ans);
    return 0;
}

