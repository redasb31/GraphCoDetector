#include <stdio.h>

int main(void)
{
	int a[4],x[2],mina,minx,j,i;
	
	mina=1000000;
	minx=1000000;
	j=0;
	
	for(i=1;i<=4;i++){
		scanf("%d",&a[i]);
		if(a[i]<=mina){
			mina=a[i];
		}
		j+=a[i];
	}
	
	for(i=1;i<=2;i++){
		scanf("%d",&x[i]);
		if(x[i]<=minx){
			minx=x[i];
		}
		j+=x[i];
	}
	
	j=j-mina-minx;
	
	printf("%d\n",j);
	
	return 0;
}