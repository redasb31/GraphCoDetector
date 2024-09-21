#include<stdio.h>
int main(void)
{
	int h1,h2,k1,k2,a,b,c,d,H,K;
	scanf ("%d%d",&h1,&h2);
	scanf ("%d%d",&k1,&k2);
	scanf ("%d%d%d%d",&a,&b,&c,&d);
	H=h1*a+h2*b+(h1/10)*c+(h2/20)*d;
	K=k1*a+k2*b+(k1/10)*c+(k2/20)*d;
	if (H>K)
	printf ("hiroshi\n");
	else if (H<K)
	printf ("kenjiro\n");
	else
	printf ("even\n");
	return 0;
}