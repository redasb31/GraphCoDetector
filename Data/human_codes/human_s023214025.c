/*
  AOJ 0135
  Title:Clock Short Hand and Long Hand
  @kankichi573
*/
#include <stdio.h>
#include <float.h>

int n,h,m;
int long_h,long_l,short_h,short_l;
char output[3][10]={"alert","warning","safe"};

int my_abs(int x)
{
  return (x>=0)?x:(-x);
}
int  hantei(int short_h,int short_l,int long_h,int long_l) 
{
  int deg=abs((short_h-long_h)*60+(short_l-long_l));
  if(deg>360)
    deg=720-deg;

  //printf("deg=%d\n",deg);

  if(deg<60)
    return(1);
  else if((60 <= deg) && (deg < 180))
    return(2);
  else
    return(3);
}


main ()
{
  int i,ret;
  scanf("%d",&n);
  {
    for(i=0;i<n;i++)
      {
	scanf("%d:%d",&h,&m);
	short_h=h;  // 30deg    tanni
	short_l=m;  // 30deg/60 tanni

	long_h = m / 5;
	long_l = (m % 5)*12;
	ret=hantei(short_h,short_l,long_h,long_l);
	printf("%s\n",output[ret-1]);
      }
  }
  return(0);
}