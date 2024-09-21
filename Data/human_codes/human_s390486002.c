#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int a, b, c, d, e, f, w = 0, s = 0, i, j, k, l;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	a *= 100;
	b *= 100;
	
	for( i = 0; a*i <= f; i++ ) {
		for( j = 0; a*i+b*j <= f; j++ ) {
			int x = a*i+b*j;
			for ( k = 0; x+c*k <= f; k++ ) {
				for ( l = 0; x+c*k+d*l <= f; l++ ) {
					int y = c*k+d*l;
					if ( x*e >= 100*y && x+y <= f ) {
						if ( s*(x+y) <= w*y ) {
							w = x+y;
							s = y;
						}
					}
				}
			}
		}
	}
	
	printf("%d %d", w, s);
	return 0;
}
