#include <stdio.h>

#define INF 100000000
#define MAX_N 1000000

typedef struct {
	int num;
	int max;
	int last;
} FIELD;

int isPrime[ MAX_N + 1 ] = { 0, 0, 1 }, corner[ 1998 ] = { 2 }, coord[ 1000001 ], m;
FIELD field[ 1002 ][ 1001 ];
const int dx[ 7 ] = { 1, 0, -1 , 0, -1, 0, 1 }, dy[ 7 ] = { 0, -1, 0, 1, 1, 1, 1 };

void dfs( int, int );

int main( void ) {
	int i, j, add, x, y, d, cnt, n;

	for ( i = 3; i <= MAX_N; i += 2 )
		isPrime[ i ] = 1;

	for ( i = 3; i * i <= MAX_N; i += 2 )
		if ( isPrime[ i ] )
			for ( j = i * 2; j <= MAX_N; j += i )
				isPrime[ j ] = 0;

	add = 1;
	for ( i = 1; i < 1998; i++ ) {
		corner[ i ] = corner[ i - 1 ] + add;
		add += i & 1;
	}

	x = y = 500;
	d = cnt = 0;
	for ( i = 1; i <= 1000000; i++ ) {
		coord[ i ] = x * 1001 + y;
		field[ x ][ y ].num = i;

		if ( i == corner[ cnt ] ) {
			d = d + 1 & 3;
			cnt++;
		}

		x += dx[ d ];
		y += dy[ d ];
	}

	for ( x = 1002; x--; field[ x ][ 1000 ].num = INF ) ;
	for ( y = 1001; y--; field[ 0 ][ y ].num = field[ 1001 ][ y ].num = INF ) ;

	for ( ; scanf( "%d %d", &m, &n ), m; printf( "%d %d\n", field[ x ][ y ].max, field[ x ][ y ].last ) ) {
		for ( i = m; i; i-- ) {
			field[ x = coord[ i ] / 1001 ][ y = coord[ i ] % 1001 ].max = INF;
			field[ x ][ y ].last = 0;
		}

		dfs( x = coord[ n ] / 1001, y = coord[ n ] % 1001 );
	}

	return 0;
}

void dfs( int x, int y ) {
	int i;

	field[ x ][ y ].max = 0;
	for ( i = 7; i-- > 4;  ) {
		int nx = x + dx[ i ], ny = y + dy[ i ];

		if ( field[ nx ][ ny ].num <= m ) {
			if ( field[ nx ][ ny ].max == INF )
				dfs( nx, ny );

			if ( field[ x ][ y ].max < field[ nx ][ ny ].max ) {
				field[ x ][ y ].max = field[ nx ][ ny ].max;
				field[ x ][ y ].last = field[ nx ][ ny ].last;
			} else if ( field[ x ][ y ].max == field[ nx ][ ny ].max && field[ x ][ y ].last < field[ nx ][ ny ].last )
				field[ x ][ y ].last = field[ nx ][ ny ].last;
		}
	}

	if ( isPrime[ field[ x ][ y ].num ] ) {
		if ( !field[ x ][ y ].max )
			field[ x ][ y ].last = field[ x ][ y ].num;

		field[ x ][ y ].max++;
	}
}