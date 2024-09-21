#include<stdio.h>
#define rep(i,n) for(int i=0;i<n;i++)
int n,l,r;
int a[51];
int main(void){
    while(1){
        scanf("%d%d%d",&n,&l,&r);
        if(n==0) break;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int cnt=0;
        for(int x=l;x<=r;x++){
            int flag=0;
            for(int i=1;i<=n;i++){
                if(x%a[i]==0){
                    if(i%2==1) cnt++;
                    flag=1;
                    break;
                }
            }
            
            if(flag==0){
                if(n%2==1);
                else cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}

