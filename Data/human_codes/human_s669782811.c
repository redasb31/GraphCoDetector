/*
AizuOnline A2488
Title
*/
#include <stdio.h>
// Select Below
//#include <stdlib.h>
//#include <string.h>
//#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
#define min(x,y) (((x)<(y))?(x):(y))
int n;
int x[1000],y[1000];
int x00,y00;  // genten
//
main()
{
  int i,len,prev;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d %d",&x[i],&y[i]);
  
  if(n==1)
    len=0;
  else
    {
      x00=x[0];y00=y[n-1];
  
      len=y00+x[n-1];
      prev=x00;
      for(i=1;i<n;i++)
	{
	  len += min(x[i]-prev,y[i]);
	}
    }
  printf("%d\n",len);
  return(0);
}