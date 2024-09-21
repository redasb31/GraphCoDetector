#include <stdio.h>
#define X 1000000007

int main(void) {
	int m,n,i;
	long a=1;
	scanf("%d %d",&m,&n);
	if(1<=m&&m<=100&&1<=n&&n<=1000000000){
		for(i=0;i<n;i++){
			a*=m%X;
		}
		printf("%d\n",a%X);
	}
	return 0;
}

