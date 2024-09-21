#include <stdio.h>

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  for ( ; ; )
  {
    int n;
    int res;

    scanf ( "%d", &n );
    if ( !n ) break ;

    for ( res = 0; n != 1; ++res )
    {
      if ( !( n % 2 ) ) n >>= 1;
      else              n   = n * 3 + 1;
    }

    printf ( "%d\n", res );
  }

  return ( 0 );
}