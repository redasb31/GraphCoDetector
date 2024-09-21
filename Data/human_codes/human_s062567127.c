#include<stdio.h>
int main()
{
	int i,k;
	char a[100][100],b[100];
	for(i=0;i<3;i++)
	{
		for(k=0;k<3;k++)
		{
			scanf("%c",&a[i][k]);
		}	
		getchar();
	}	
	printf("%c%c%c",a[0][0],a[1][1],a[2][2]);
	return 0;
 } 