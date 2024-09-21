/*
  AOJ 2518
  Title:　B2D
  @kankichi573
*/
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
// #include <math.h>
// #include <float.h>
// #include <stdlib.h>

int N;
int total_len;
char buf[1024];

// ABCABC ABCDABCD etc => true
int pattern(char * s,int len)
{
  return(0==strncmp(s,s+len,len));
}
display(char *p,int len)
{
  int i;

  for(i=0;i<len;i++,p++)
      printf("%c",*p);
  printf("\n");
}

int count_shurui(int level)
{
  int i,j;
  int cnt;
  int nc;

  nc=1<<level;

  for(i=0,cnt=0;i<total_len;i += nc)
    {
      //display(buf+i,nc);

      if(pattern(buf+i,1<<(level-1)))
	continue;
      for(j=0;j<i-1;j += nc)
	{
	  if(0==strncmp(buf+i,buf+j,nc))
	    goto NEXT;
	}
      cnt++;
    NEXT:
      ;
    }

  return(cnt);
}
int solve()
{
  int i,cnt,ret;

  for(i=1,cnt=0;i<=N;i++)
    {
      ret = count_shurui(i);
      //printf("%d %d\n",i,ret);
      cnt += ret;
    }
  return(cnt);
}
main()
{
 
  int i,ret;

  scanf("%d",&N);
  total_len = 1<<N;
  scanf("%s",buf);

  //printf("%d\n",b2n(buf,4));
  //printf("p166=%d\n",pattern(166,4));

  ret=solve(buf);
  //printf("ANS=");
  printf("%d\n",ret);
    
  return(0);
 
}