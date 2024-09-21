#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,i;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	if(a<=0){
		i=-a*c+d+b*e;
		printf("%d\n",i);
	}
	else{
	i=((b-a)*e);
	printf("%d\n",i);
	}
	return 0;
	}
	
