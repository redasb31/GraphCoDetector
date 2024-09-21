#include<stdio.h>
int main(){
	int x,a,b;
	scanf("%d %d %d",&x,&a,&b);
	printf("%d\n",(x-a)%b);
	return 0;
}