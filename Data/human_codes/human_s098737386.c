#include<stdio.h>
int main(void)
{
	int n,a,b,x,y;
	scanf("%d %d %d",&n,&a,&b);
	x=a*n;
	y=b;
	if(x>y){
		printf("%d\n",x);
	}
	else{
		printf("%d\n",y);
	}
	return 0;
}




