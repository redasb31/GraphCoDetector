#include <stdio.h>

#define swap( x, y ) do { double tmp; tmp = x; x = y; y = tmp; } while ( 0 )

int rel_l_l( double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, double *x, double *y ) {
	double a, b, c, d;
	int rel;

	if ( x1 < x0 ) {
		swap( x0, x1 );
		swap( y0, y1 );
	}
	if ( x3 < x2 ) {
		swap( x2, x3 );
		swap( y2, y3 );
	}

	if ( x0 != x1 ) {
		a = ( y0 - y1 ) / ( x0 - x1 );
		b = ( x0 * y1 - x1 * y0 ) / ( x0 - x1 );
	}
	if ( x2 != x3 ) {
		c = ( y2 - y3 ) / ( x2 - x3 );
		d = ( x2 * y3 - x3 * y2 ) / ( x2 - x3 );
	}

	rel = 1;
	if ( x0 == x1 ) {
		*x = x0;
		if ( x2 == x3 )
			if ( x0 == x2 ) {
				if ( y1 < y0 )
					swap( y0, y1 );
				if ( y3 < y2 )
					swap( y2, y3 );

				if ( y3 < y0 || y1 < y2 )
					rel = 3;
				else if ( y3 == y0 || y1 == y2 ) {
					*y = y3 == y0 ? y0 : y1;
					rel = 4;
				} else
					rel = 5;
			} else
				rel = 2;
		else {
			*y = c * *x + d;
			if ( *x < x2 || x3 < *x || *y < ( y0 < y1 ? y0 : y1 ) || ( y0 < y1 ? y1 : y0 ) < *y )
				rel = 0;
		}
	} else {
		if ( x2 == x3 ) {
			*x = x2;
			*y = a * *x + b;
			if ( *x < x0 || x1 < *x || *y < ( y2 < y3 ? y2 : y3 ) || ( y2 < y3 ? y3 : y2 ) < *y )
				rel = 0;
		} else {
			if ( a == c ) {
				if ( b == d )
					if ( x3 < x0 || x1 < x2 )
						rel = 3;
					else if ( x3 == x0 || x1 == x2 ) {
						*x = x3 == x0 ? x0 : x1;
						rel = 4;
					} else
						rel = 5;
				else
					rel = 2;
			} else {
				*x = ( -b + d ) / ( a - c );
				if ( *x < x0 || x1 < *x || *x < x2 || x3 < *x )
					rel = 0;
			}
			*y = a * *x + b;
		}
	}

	return rel;
}


int main( void ) {
	int q;

	scanf( "%d", &q );
	while ( q-- ) {
		int rel;
		double x0, y0, x1, y1, x2, y2, x3, y3, x, y;

		scanf( "%lf %lf %lf %lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3 );

		rel = rel_l_l( x0, y0, x1, y1, x2, y2, x3, y3, &x, &y );

		printf( "%d\n", rel == 1 || rel == 4 ? 1 : 0 );
	}

	return 0;
}