#include <stdio.h>

#define SQ(X) \
  ((X)*(X))
#define MIN(D,S) \
  (D) = ( (S) < (D) ? (S) : (D) )

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  for ( ; ; )
  {
    int x, y, z, R, n;

    scanf ( "%d%d%d", &x, &y, &z );
    if ( x == 0 && y == 0 && z == 0 ) break;

    R = SQ(x) + SQ(y);
    MIN( R, SQ(y) + SQ(z) );
    MIN( R, SQ(z) + SQ(x) );

    scanf ( "%d", &n );
    while ( n-- )
    {
      int r;

      scanf ( "%d", &r );
      puts ( SQ(r * 2) > R ? "OK" : "NA" );
    }
  }

  return ( 0 );
}