#include<stdio.h>

int main(void){
	
		 double a,b;
	
		scanf("%lf%lf",&a,&b);

	
	if(a>b)
		puts("GREATER");
	else if(a<b)
		puts("LESS");
	else
		puts("EQUAL");
		
	return 0;
}

