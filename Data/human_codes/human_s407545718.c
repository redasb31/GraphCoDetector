#include <stdio.h>

int e;
long long f;

int check (long long a,int b)
{
	int c;
	if(a<=f){
		if(b==7){
			e++;
		}
	}
/*	if(a<=f){
		printf("%d\n",a);
	}*/
	if(a<=f){
		check(a*10+3,b|1);
		check(a*10+5,b|2);
		check(a*10+7,b|4);
	}
	return e;
}
	
int main(void)
{
	int d;
	scanf("%lld",&f);
	d=check(0,0);
	printf("%d\n",d);
	return 0;
}