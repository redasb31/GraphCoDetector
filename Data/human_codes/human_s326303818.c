/*
  AOJ 2044
  Title:Lying about Your Age
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
#define min(x,y) (((x)<(y))?(x):(y))

int a,c,saba;
char b[9];
int radix;

int dec2M(char *s,int rad,int num)
{
  int d,pos,i;

  memset(s,0,9);
  pos=0;
  while(1)
    {
      d = num % rad;
      if(d > 9)
	return(0);
      s[0]=d+'0';
      num /= rad;
      if(num==0)
	break;
      for(i=pos+2;i>0;i--)
	s[i]=s[i-1];
      pos++;
    }
  return(-1); // -1: '0~9' only
              // 0:  include 'a'~
}
int M2dec(char *s,int rad)
{
  int i,ret;

  ret=0;
  while(1)
    {
      ret+=(*s-'0');
      s++;
      if(!*s)
	break;
      ret*=rad;
    }
  return(ret);
}

int cal_radix(int num,char *s)
{
  int i,limit,val;
  if(strlen(s)>2)
    limit=10;
  else
    limit=16;
  for(i=2;i<=16;i++)
    {
      val=M2dec(s,i);

      if(val==num)
	return(i);
      if(val>num)
	break;
    }
  return(-1);
}


int next_age(int num,int radix)
{
  int i=radix;
  char s[9];

  if((num % radix)==10 && (num/radix)==1 && radix < 16)
    return(radix+1);

  for(i=radix;i>1;i--)
    {
      if(dec2M(s,i,num))
	return(i);
    }
}
main()
{
  int ret,i;
  char result[9];
  
  while(scanf("%d %s %d",&a,&b[0],&c) && (a!=-1||c!=-1))
    {
      radix=cal_radix(a,b);
      if(radix==-1)
	{
	  printf("-1\n");
	  continue;
	}
      for(i=a+1;i<=c;i++)
	{
	  radix=next_age(i,radix);
	  dec2M(result,radix,i);
	  //printf("%d %d %s\n",i,radix,result);
	}
      dec2M(result,radix,c);
      printf("%s\n",result);
    }
  
  return(0);
}