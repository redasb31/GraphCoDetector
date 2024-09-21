#include<stdio.h>
#include<string.h>
int main()
{
	char a[100000],x;
	int i,j,t;
	scanf("%s",a);
	i=strlen(a);
	x=a[i/2+(i%2!=0)-1];
	for(j=i/2;j>=0;j--)if(a[j]!=x||a[i-1-j]!=x)break;
	t=i-j;
	if(t%2!=0)t--;
	printf("%d\n",t);
	return 0;
}
