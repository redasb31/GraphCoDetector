#include <stdio.h>
#include <string.h>

char imgA[50][50] = { 0 };
char imgB[50][50] = { 0 };

int main()
{
	int n, m;
	
	scanf( "%d %d", &n, &m );
	
	int i;
	for ( i = 0; i < n; i++ )
	{
		scanf( "%s", imgA[i] );
	}
	for ( i = 0; i < m; i++ )
	{
		scanf( "%s", imgB[i] );
	}
	
	char* p_adrs;
	int j = 0;
	int eq_flg = 0;
	for ( i = 0; i < n - m; i++ )
	{
		p_adrs = strstr( imgA[i], imgB[0] );
		
		if ( NULL != p_adrs )
		{
			j = ( imgA[i] - p_adrs ) / sizeof( char* );
			eq_flg = 1;
			break;
		}
	}
	
	if ( 0 == eq_flg )
	{
		printf("No\n");
		return 0;
	}
	
	int b, bj;
	for ( b = 1; b < m; b++ )
	{
		p_adrs = strstr( imgA[i+b], imgB[b] );
		if ( NULL == p_adrs )
		{
			printf("No\n");
			return 0;
		}
		
		bj = ( imgA[i+b] - p_adrs ) / sizeof( char* );
		
		if ( j != bj )
		{
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
	
	return 0;
}

