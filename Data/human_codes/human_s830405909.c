#include <stdio.h>

int a[1<<20];
int cnt[1<<20];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<1<<n;i++)scanf("%d",a+i);
	int ans=0;
	for(int i=0;i<1<<n;i++){
		if(cnt[i]&&!a[i]){
			puts("-1");
			return 0;
		}
		if(!cnt[i]&&a[i])ans++;
		if(a[i])for(int k=0;k<n;k++)if((~i>>k)&1)cnt[i^(1<<k)]++;
	}
	printf("%d\n",ans);
}
