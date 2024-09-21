/*
AizuOnline A0086
Title Patrol
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
#define NO_OF_CROSS 100
int hist[NO_OF_CROSS];
//
main()
{
  int c1,c2,i,ans;

  memset(hist,0,sizeof(hist));
  while(1)
    {
      if(EOF==scanf("%d %d ",&c1,&c2))
	break;
#ifdef DEBUG
      printf("%d %d\n",c1,c2);
#endif
      if(c1 || c2)
	{
	  hist[c1]++;
	  hist[c2]++;
	}
      else
	{
	  ans=0;
	  if((hist[1] & 1)==0)
	    ans=1;
	  else if((hist[2] & 1)==0)
	    ans=1;
	  else
	    for(i=3;i<NO_OF_CROSS;i++)
	      if(hist[i] & 1)
		ans=1;
#ifdef DEBUG
	  printf("h1234:%d %d %d %d\n",hist[1],hist[2],hist[3],hist[4]);
#endif
	  printf("%s\n",ans?"NO":"YES");
	  memset(hist,0,sizeof(hist));
	}
    }
  return(0);
}