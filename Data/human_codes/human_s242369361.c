#include <stdio.h>

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int c = 0;

  for ( ; ; )
  {
    char  s[ 128 ];
    char  * sp,
          * ep;

    if ( fgets ( s, sizeof ( s ), stdin ) == NULL ) break ;

    for ( ep = s; *ep != '\n'; ++ep ) ;
    --ep;

    for ( sp = s; sp < ep; ++sp, --ep )
    {
      if ( *sp != *ep )
      {
        goto CONTT;
      }
    }
    ++c;

CONTT: ;
  }

  printf ( "%d\n", c );

  return ( 0 );
}