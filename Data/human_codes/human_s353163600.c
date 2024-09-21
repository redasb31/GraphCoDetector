#include<stdio.h>

int main(){
		int n,k;
		scanf("%d%d",&n,&k);
		int a[n],memo[200000]={0},count=0,mini=200000,i,ans=0,mm;
		for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				memo[a[i]-1]++;
		}
		for(i=0;i<n;i++){
				if(memo[i]>0)count++;
		}
		if(count<=k)puts("0");
		else {
				while(count>k){
						mini=200000;
						for(i=0;i<n;i++){
								if(memo[i]>0&&mini>memo[i]){
										mini=memo[i];
										mm=i;
								}
						}
						ans+=mini;
						memo[mm]=0;
						count--;
				}
				printf("%d\n",ans);
		}
		return 0;
}

