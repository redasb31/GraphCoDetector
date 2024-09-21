#include<stdio.h>
int main(void)
{
	int A,B,i;
	int cnt=0;
	int sum=0;
	scanf("%d%d",&A,&B);
	for(i=1;i<100;i++)
	{
		sum=(A-1)*i+1;
		if(sum>=B)
		break;
		else
		cnt++;break;
	}
	printf("%d",cnt);
	return 0;
}
