#include <stdio.h>

int main(void) {
	int num_100;
	int num_500;
	int num_1000;
	int in_A,in_B;
	int rest;
	while(1) {
		scanf("%d%d",&in_A,&in_B);
		if(in_A==0 && in_B==0)break;
		rest=in_B-in_A;
		num_1000=rest/1000;
		rest%=1000;
		num_500=rest/500;
		rest%=500;
		num_100=rest/100;
		printf("%d %d %d\n",num_100,num_500,num_1000);
	}
	return 0;
}