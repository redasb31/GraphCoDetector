#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char a[1000001],b[1000001];
	int x,j,i;
	while(scanf("%s",&a) != EOF)
	{
		j = 0;
		x = 0;
		for( i = 0; i < strlen(a); i++ )
		{
			if(a[i] != 'x')
			{
				b[j] = a[i];
				j++;
			}
			else x++;
		}
		
		
		
		for( i = 0; i < strlen(a)/2; i++ )
		{
			if( a[i] != a[strlen(a) - 1 - i])break;
		}
		if( i < strlen(a)/2){
			for( i = 0; i < j/2; i++ )
		{
			if( b[i] != b[j - 1 - i])break;
		}
		if( i < j/2)printf("-1\n");
		else printf("%d\n",x);
		}
		else printf("0\n");
		
	} 
	return 0;
}