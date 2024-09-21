#include <stdio.h>
#define bit(n,m)(((n)>>(m))&1)

int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	int s=0;
	while(c--){
		int t;
		scanf("%d",&t);
		s|=1<<t;
	}
	for(int x=0;x<1<<n;x++)if((x&s)==x){
		printf("%d:",x);
		for(int k=0;k<n;k++)if(bit(x,k))printf(" %d",k);
		puts("");
	}
}
