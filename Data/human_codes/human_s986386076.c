#include <stdio.h>

int main(void) {
	int n;
	while(1) {
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",n%3==1?6:30);
	}
	return 0;
}