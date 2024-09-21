#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,f,x,y,z;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	scanf("%d",&f);
	x=100;
	if(x>a) {
		x=a;
	}
	if(x>b) {
		x=b;
	}
	if(x>c) {
		x=c;
	}
	if(x>d) {
		x=d;
	}
	if(e>f) {
		y=f;
	}
	else if(f>e) {
		y=e;
	}
	z=(a+b+c+d+e+f)-(x+y);
	printf("%d\n",z);
	return 0;
}