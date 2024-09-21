#include<stdio.h>
#include<math.h>
int main(){
	int x,h;
	for(;scanf("%d%d",&x,&h)&&(x||h);){
		printf("%lf\n",x*x+sqrt(pow(x/2.0,2)+pow(h,2))*(2.0*x));
	}
	return 0;
}