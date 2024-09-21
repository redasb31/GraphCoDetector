#include<stdio.h>
#include<math.h>
int N,T,i;
char f[999];
double R=0;

int main()
{
	scanf("%lld%lld\n%s",&N,&T,f);
	for(i=0;f[i];i++)
		if('0'<=f[i]&&f[i]<='9')
			R+=pow(N*1.0,f[i]-'0');
	if(R*T-1000000000>=0.000000001)
		puts("TLE");
	else
		printf("%.0f\n",R*T);
	return 0;
}