#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main () {
	double xa, ya, xb, yb, xc, yc, xd, yd, xe, ye;
	double tac, tbd, sac, sbd;
	char c[10000];
	int i;
	while(scanf("%s",&c)!=EOF) {
		xa=atof(strtok ( c, "," ));
		ya = atof ( strtok ( NULL, "," ) ); 
		xb = atof ( strtok ( NULL, "," ) ); 
		yb = atof ( strtok ( NULL, "," ) ); 
		xc = atof ( strtok ( NULL, "," ) ); 
		yc = atof ( strtok ( NULL, "," ) ); 
		xd = atof ( strtok ( NULL, "," ) ); 
		yd = atof ( strtok ( NULL, "," ) ); 
		sac = ( yc - ya ) / ( xc - xa );
		tac = ya - xa*sac;
		sbd = ( yd - yb ) / ( xd - xb );
		tbd = yb - xb*sbd;
		xe = ( tac - tbd ) / ( sbd - sac );
		ye = xe*sac + tac;
		if(( ( xa <= xe&&xe <= xc ) || ( xc <= xe&&xe <= xa ) ) && ( ( ya <= ye&&ye <= yc ) || ( yc <= ye&&ye <= ya ) )) {
			printf ( "YES\n" );
		} else {
			printf ( "NO\n" );
		}
		//printf ( "%f %f\n", xb, yb );
	}
	return 0;
}