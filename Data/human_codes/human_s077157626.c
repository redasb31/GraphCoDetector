#include<stdio.h>
int main(void){
	int x1,x2,c;
	scanf("%d %d",&x1,&x2);
	if(x1<x2){
		c=x2-x1;
	}
	else{
		c=x1-x2;
	}
	printf("%d\n",c);
	return 0;
}
