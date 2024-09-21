#include<stdio.h>
#include<stdlib.h>


typedef long long llong ;

typedef struct
{
	llong size ;
	llong value ;

} Data ;

#define N_MAX 500000
Data art[ N_MAX ] ;

inline int cmp( const Data *a ,const Data *b )
{
	int ret = a->size == b->size ? a->value - b->value : -( a->size < b->size ) ;

	return ret ? ret : 1 ;
}

inline llong max( llong a ,llong b )
{
	return a > b ? a : b ;
}


int main( void )
{
	int N ;
	scanf( "%d" ,&N ) ;

	int i ;
	for( i = 0 ; i < N ; ++i )
	{
		scanf( "%lld %lld" ,&art[ i ].size ,&art[ i ].value ) ;
	}

	qsort( art ,N ,sizeof( Data ) ,cmp ) ;

	llong min_size	= art[ 0 ].size		;
	llong sum_value	= art[ 0 ].value	;

	llong ans = art[ 0 ].value ;
	for( i = 1 ; i < N ; ++i )
	{
		llong value	= art[ i ].value	;
		llong size	= art[ i ].size		;

		llong tmp =  sum_value + value  - ( size -  min_size ) ;
		if( tmp < value )
		{
			ans = max( ans ,value ) ;

			sum_value	= value	;
			min_size	= size	;
		}

		else
		{
			ans = max( ans ,tmp ) ;

			sum_value += value ;
		}
	}

	printf( "%lld\n" ,ans ) ;

	return 0 ;
}
