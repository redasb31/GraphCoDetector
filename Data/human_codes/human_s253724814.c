#include<stdio.h>
int main()
{
	int n,k,i=1;
    double s;
	scanf("%d%d",&n,&k);
	s=k;
    while(n/k!=0)
	{
		i++;
		n/=k;
	}
	printf("%d",i);
		
	
	return 0;
}