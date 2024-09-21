/*
AizuOnline A1302
Twenty Questions
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#define DEBUG 0
#define DEBUG2 0
#define CHK 1

int M=11,N=17,BIT;
int Objects[128];
int log_2(int  x)
{
  if(x > 64)
    return 7;
  else if(x > 32)
    return 6;
  else if(x > 16)
    return 5;
  else if(x > 8)
    return 4;
  else if(x > 4)
    return 3;
  else 
    return 2;
}

int comp(int * a,int * b)
{
  return( (*a & BIT) < (*b & BIT));
}

int all_isolate(int * objects,int objcnt)
{
  int i,j;
  int cnt;

#if DEBUG2
  printf("(%d)",objcnt);
  for(i=0;i<objcnt;i++)
    printf("%d:",objects[i]);
  printf("\n");
#endif
  
  for(i=0;i<M;i++)
    {
      cnt=0;
      for(j=0;j<objcnt;j++)
        cnt += ((1<<i)&objects[j])?1:0;
      
      if(cnt == 0 ||cnt == objcnt||cnt == 1||cnt == objcnt-1)
        continue;
      else
        return(0);
    }
  return(-1);
}

int maxquestions(int * objects,int objcnt,int depth)
{
  int i,j,k,cnt;
  int ret1,ret2;
  int maxret,minmaxret;
  int mintimes = log_2(objcnt);
#if DEBUG
  printf("(%d)",objcnt);
  for(i=0;i<objcnt;i++)
    printf("%d:",objects[i]);
  printf("\n");

#endif
  
  if(objcnt <= 1)
    return(0);
  if(objcnt==2)
    return(1);
  if(objcnt==3)
    return(2);
  
#if CHK
  if(all_isolate(objects,objcnt))
    return(objcnt-1);
#endif
  
  minmaxret=INT_MAX;
  for(i=0;i<M;i++)
    {
      cnt = 0;
      BIT = 1<<i; 
      for(j=0;j<objcnt;j++)
	if(objects[j] & BIT)
	    cnt++;
	
      if(cnt == 0||cnt == objcnt)
        continue;
 
      if(objcnt == 4)
	{
	  if(cnt == 2)
	    maxret = 2;
	  else
	    maxret = 3;
	  goto AAA;
	}
      if(objcnt ==5 && (cnt == 2 || cnt == 3))
	{
	  maxret = 3;
	  goto AAA;
	}

      qsort(objects,objcnt ,sizeof(int), comp);
#if DEBUG
      printf("MASK=%d cnt=%d",BIT,cnt);
      printf("(%d)",objcnt);
      for(k=0;k<cnt;k++)
	printf("%d:",objects[k]);
      printf("|");
      for(k=0;k<objcnt-cnt;k++)
	printf("%d:",objects[k+cnt]);
      printf("\n");
      /*        
      if(depth == 1)
	return(0);
      */
#endif

      ret1=maxquestions(objects,cnt,depth+1);
      ret2=maxquestions(objects+cnt,objcnt-cnt,depth+1);
      maxret=((ret1>ret2)?ret1:ret2)+1;
    AAA:
      if(minmaxret > maxret)
	minmaxret=maxret;
      if(mintimes == minmaxret)
	break;
    }
    
  return(minmaxret);
}




main()
{
  char buffer[100];
  char *x;
  int i,j;

  while(EOF != scanf(" %d %d",&M,&N) && (M || N))
    {
      /*       printf("M=%d N=%d\n",M,N);
       */

      for(i=0;i<N;i++)
	{
	  for(j=0;j<100;j++)
	    buffer[j]=0;
	  scanf("%s",buffer);
  
	  Objects[i]=(int)strtol(buffer,&x,2);
	}
      printf("%d\n",maxquestions(Objects,N,0));


    }
  return(0);
}