#include<stdio.h>
int main(void)
{
	long long a,b,c,k,sa1,sa2,sum;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&k);
	sa1=k-a;
	sum=0;
	sum+=k-sa1;
	if(sa1>=1){
	   sa2=sa1-b;
	   if(sa2>=1){
		   sum-=sa2;
	   }
	}
	printf("%lld\n",sum);
	return 0;
}