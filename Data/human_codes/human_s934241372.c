/*
AizuOnline A1202
Title
*/
#include <stdio.h>
// Select Below
#include <stdlib.h>
//#include <string.h>
#include <float.h>
//#include <math.h>
//#include <limits.h>
//Global data section
int n;
double cx[100],cy[100],s[100];

double x[200],y[200];
//
int d_comp(const void *x , const void *y)
{
  return(*(double *)x > *(double *)y);
}
int inrects(double x,double y)
{
  int i;

  for(i=0;i<n;i++)
    if(x >= cx[i]-s[i] && x<= cx[i]+s[i] && y >= cy[i]-s[i] && y<= cy[i]+s[i])
      return(-1);
	
  return(0);
}
printx()
{ int i;
  for(i=0;i<6;i++)
    printf("%.2lf:",x[i]);
  printf("\n");
}
main()
{
  int i,j,cnt,tim;
  double ssum;

  tim=0;
  while(scanf("%d",&n) && n)
    {
      cnt = 0;
      for(i=0;i<n;i++)
	{
	  scanf("%lf %lf %lf",&(cx[i]),&(cy[i]),&(s[i]));
	  x[cnt]=cx[i]+s[i];
	  x[cnt+1]=cx[i]-s[i];
	  y[cnt]=cy[i]+s[i];
	  y[cnt+1]=cy[i]-s[i];
	  cnt+=2;
	}
      
      
      qsort(x,cnt,sizeof(double),d_comp);
      qsort(y,cnt,sizeof(double),d_comp);
      

      ssum=0.0;
      for(i=0;i<cnt-1;i++)
	for(j=0;j<cnt-1;j++)
	  {

	    if(inrects((x[i]+x[i+1])/2,(y[j]+y[j+1])/2))
	      {

	      ssum += ((x[i+1]-x[i])*(y[j+1]-y[j]));
	      }
	  }
      tim++;
      printf("%d %.2lf\n",tim,ssum);
    }
return(0);
}