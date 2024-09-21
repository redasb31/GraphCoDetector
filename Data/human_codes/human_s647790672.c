/*
  AOJ 1330
  Title:Never Wait for Weights
  @kankichi573
  14/03/20 TLE
*/
#include <stdio.h>
#include <setjmp.h>
jmp_buf jb;
#define QUERY   100000
#define SAMPLES 100000
int cnt; //! query count
int N,M;
int a[QUERY],b[QUERY],c[QUERY],d[SAMPLES+1];
int modified;
int answer;
int buf[SAMPLES+1];
int buflen[SAMPLES+1];
void clear()
{
  int i;
  for(i=0;i<QUERY;i++)
    d[i]=-1;

}
void step(int level,int target)
{
  int i,p,j,diff;

  buflen[level+1]=0;
  for(i=0;i<buflen[level];i++)
    {
      p=buf[i];
      {
	//printf("::%d\n",p);
	for(j=0;j<cnt;j++)
	  {
	    if(a[j]==p && d[b[j]]<0)
	      {
		diff=d[p]+c[j];
		d[b[j]]=diff;
		if(b[j]==target)
		  {
		    answer=diff;
		      //printf("LONGJUMP=%d %d %d\n",answer,d[i],c[j]);  
		    longjmp(jb,1);
		  }
		buf[buflen[level+1]++]=b[j];
		modified=-1;
	      }
	    if(b[j]==p && d[a[j]]<0)
	      {
		diff=d[p]-c[j];
		d[a[j]]=diff;
		if(a[j]==target)
		  {
		    answer=diff;
		    longjmp(jb,1);
		  }
		buf[buflen[level+1]++]=a[j];
		modified=-1;
	      }
	  }
	}
    }
}
void solve(int from,int to)
{
  int level;
  clear();
  
  d[from]=0;buf[0]=from;buflen[0]=1;modified=-1;
  for(level=0;modified;level++)
    {
      modified=0;
      if(setjmp( jb ) == 0 ) 
	{
	  step(level,to);
	}
      else
	return;
    }

}
dump()
{
  int i;

  for(i=0;i<cnt;i++)
    printf("%d~%d = %d\n",a[i],b[i],c[i]);
  for(i=1;i<=N;i++)
    printf("%d:%d\n",i,d[i]);
}
main()
{
  int i,x,y;
  char q;

  while(scanf("%d %d ",&N,&M) && (N||M))
    {

      cnt=0;
      for(i=0;i<M;i++)
	{
	  scanf("%c",&q);
	  if(q=='!')
	    {
	      scanf("%d %d %d ",&a[cnt],&b[cnt],&c[cnt]);
	      cnt++;
	    }
	  else if(q=='?')
	    {
	      scanf("%d %d ",&x,&y);
	      answer=-1;
	      solve(x,y);
	      if(answer!=-1)
		printf("%d\n",answer);
	      else
		printf("UNKNOWN\n");
	    }
	}
      //dump();
    }
  return(0);
}