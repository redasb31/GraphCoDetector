#include<stdio.h>

int main(){
	int n,i;
	long tmp,a[100001]={0},ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp>100000)ans++;
		else a[tmp]++;
	}
	for(i=0;i<=100000;i++){
		if(i<a[i])ans+=a[i];
		else ans+=a[i]-a;
	}
	printf("%ld\n",ans);
	return 0;
}