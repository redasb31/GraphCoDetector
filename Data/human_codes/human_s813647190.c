#include<stdio.h>

int main(void){
	int n,ans,i;
	
	while(scanf("%d",&n)!=EOF){
		ans=n*(n+1)/2+1;
		
		printf("%d\n",ans);
	}
	
	return 0;
}