#include <stdio.h>
#include <stdlib.h>

#define MAX_N 101000
#define SWAP( a, b ) do { int tmp; tmp = a; a = b; b = tmp; } while( 0 )

int isPrime[ MAX_N + 1 ] = { 0, 0, 1 };

void insertionSort( int *, int );
void quickSort( int *, int );
int median( int, int, int );

int main( void ) {
	int i, j, N, P, cnt, p[ 22 ], sum[ 253 ];

	for ( i = 3; i <= MAX_N; i += 2 )
		isPrime[ i ] = 1;

	for ( i = 3; i * i <= MAX_N; i += 2 )
		if ( isPrime[ i ] )
			for ( j = i * 2; j <= MAX_N; j += i )
				isPrime[ j ] = 0;

	for ( ; scanf( "%d %d", &N, &P ), N != -1; printf( "%d\n", sum[ P - 1 ] ) ) {
		cnt = 0;
		for ( i = N + 1; cnt < 22; i++ )
			if ( isPrime[ i ] )
				p[ cnt++ ] = i;

		cnt = 0;
		for ( i = 0; i < 22; i++ )
			for ( j = i; j < 22; j++ )
				sum[ cnt++ ] = p[ i ] + p[ j ];

		quickSort( sum, 253 );
	}

	return 0;
}

void insertionSort( int *data, int n ) {
	int i, j, tmp;

	for ( i = 1; i < n; i++ ) {
		tmp = data[ i ];

		if ( data[ i - 1 ] > tmp ) {
			j = i;
			do {
				data[ j ] = data[ j - 1 ];

				j--;
			} while ( j && data[ j - 1 ] > tmp );

			data[ j ] = tmp;
		}
	}
}

void quickSort( int *data, int n ) {
	int low[ 30 ] = { 0 }, high[ 30 ] = { n - 1 }, sp = 1;

	while ( sp-- ) {
		int l = low[ sp ], r = high[ sp ];

		if ( l < r ) {
			int i = l, j = r, pivot = median( data[ i ], data[ ( i + j ) / 2 ], data[ j ] );

			while ( 1 ) {
				for ( ; data[ i ] < pivot; i++ ) ;
				for ( ; pivot < data [ j ]; j-- ) ;
				if ( i >= j )
					break;

				SWAP( data[ i ], data[ j ] );

				i++;
				j--;
			}

			if ( i - l < 20 )
				insertionSort( data + l, i - l );
			else {
				low[ sp ] = l;
				high[ sp ] = i - 1;
				sp++;
			}

			if ( r - j < 20 )
				insertionSort( data + j + 1, r - j );
			else {
				low[ sp ] = j + 1;
				high[ sp ] = r;
				sp++;
			}
		}
	}
}

int median( int x, int y, int z ) {
	if ( x < y )
		if ( y < z )
			return y;
		else if ( z < x )
			return x;
		else
			return z;
	else if ( z < y )
		return y;
	else if ( x < z )
		return x;
	else
		return z;
}