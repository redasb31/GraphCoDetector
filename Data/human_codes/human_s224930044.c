#include<stdio.h>
int main()
{
	int s[100000];
	int n,i,m=0;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for (i=0;i<n;i++){
		while(s[i]=s[i+1])
		{
			s[i+1]+=1;
			m++;
		}
	}
	printf("%d",m);

	return 0;
	
}
