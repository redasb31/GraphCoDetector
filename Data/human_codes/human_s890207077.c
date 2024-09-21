#include<stdio.h>
int main(void)
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	if(a<=b && a<=c && a<=d){
		a=b+c+d;
	}
	else if(b<=a && b<=c && b<=d){
		a=a+c+d;
	}
	else if(c<=a && c<=a && c<=a){
		a=a+b+d;
	}
	else{
		a=a+b+c;
	}
	if(e<=f){
		e=f;
	}
	printf("%d\n",a+e);
	return 0;
}
