#include <stdio.h>

int main( void ) {
	int n, num_d, d[ 10 ];

	while ( scanf( "%d", &n ), n >= 0 ) {
		num_d = 0;
		do {
			d[ num_d++ ] = n % 4;
		} while ( n /= 4 );

		while ( num_d-- )
			printf( "%d", d[ num_d ] );
		putchar( '\n' );
	}

	return 0;
}