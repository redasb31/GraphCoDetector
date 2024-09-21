#include<stdio.h>
#include<string.h>
int main()
{
	int n,i;
	int dp;
	while (scanf("%d",&n) != EOF) {
		dp=1;
		for (i=1;i<=n;i++) dp+=i;
		printf("%d\n",dp);
	}
	return 0;
}