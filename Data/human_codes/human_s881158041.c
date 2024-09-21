#include<stdio.h>
int main(void)
{
	int f,N,i,x,y,b,p,g;
	scanf("%d",&N);
	for(i=0;i<N;i++){
	scanf("%d %d %d %d",&x,&y,&b,&p);
	g=x*b+y*p;
	f=g*0.8;
	if(x>=5&&y>=2){
	printf("%d\n",f);
	}
	else{
	printf("%d\n",g);
	}
	}
	return 0;
}