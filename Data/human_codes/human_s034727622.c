#include <stdio.h>

int main(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<=c<=b){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	
	return 0;
}