#include<stdio.h>

int main(void){
	int h,w,r=0,i,n;
	scanf("%d%d",&h,&w);
	for(i = 1;i <= h*w;i++){
		scanf("%d",&n);
		r+=n;
	}
	printf("%d\n",r);
	return 0;
}