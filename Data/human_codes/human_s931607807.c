#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ABS(X) \
  ( (X) < 0 ? -(X) : (X) )
#define DIST(A,B,W) \
  ( ABS( (A) / (W) - (B) / (W) ) \
  + ABS( (A) % (W) - (B) % (W) ) )
#define MIN(A,B) \
  ( (B) < (A) ? (B) : (A) )

static int n;
static int a;
static int b;
static int c;
static int d;

int
main (
  int   argc,
  char *argv[ ]
  )
{
  int res = INT_MAX;
  int w;

  scanf ( "%d", &n );
  scanf ( "%d%d%d%d", &a, &b, &c, &d );
  --a; --b; --c; --d;

  for ( w = 1; w <= n; ++w )
  {
    res = MIN( res, DIST( a, b, w ) + DIST( c, d, w ) );
  }
  printf ( "%d\n", res );

  return ( EXIT_SUCCESS );
}