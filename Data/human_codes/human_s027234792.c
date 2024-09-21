#include<stdio.h>

int main()
{
	int a ,b ;
	scanf( "%d %d" ,&a ,&b ) ;


	int handan_a = a ;
	int handan_b = 0 ;

	int seki = a * b ;
	int same = 1 ;
	int different = 0 ;


	int i ;
	for( i = 1 ; i < 6 ; i++ )
	{
		scanf( "%d %d" ,&a ,&b ) ;

		if( seki == a * b )
		{
			if( handan_a == a || handan_a == b )
			{
				same++ ;
			}
			else
			{
				different++ ;
			}
		}
		else
		{
			if( handan_b == 0 )
			{
				handan_b = a * b ;
			}

			if( handan_b == a * b )
			{
				different++ ;
			}
		}
	}


	if( ( same == 4 && different == 2 ) | ( same == 2 && different == 4 ) == 1 || same == 6 )
	{
		puts( "yes" ) ;
	}
	else
	{
		puts( "no" ) ;
	}


	return 0 ;
}