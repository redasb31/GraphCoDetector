/*
  AOJ 2082
  Title:Goofy Converter
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#define max(x,y) (((x)>(y))?(x):(y))
jmp_buf jb;
int N,M;
int L[1000];
int output[1012];
int rel[1012];
int varcnt;
int errno;
int errpos;
void fil_rel(int output[],int rel[],int varc,int val)
{
  int i;

  for(i=0;i<N+M-1;i++)
    if(rel[i]==varc)
      {
	if(output[i]==-1)
	  output[i]=val;
	else if(output[i]!=val)
	  {
	    errno=4;errpos=i;
	    longjmp(jb,1);
	  }
      }
}
void fill_blank(int L[],int output[],int rel[])
{
  int i,j,c0,c1,cr;
  
  for(i=0;i<N;i++)
    {
      c0=c1=0;
      for(j=i;j<i+M;j++)
	{
	  if(output[j]==0)
	    c0++;
	  else if(output[j]==1)
	    c1++;
	}
      cr=M-c0-c1;
      if(rel[i]!=-1 && output[i]!=-1)
	fil_rel(output,rel,rel[i],output[i]);

      if(cr==0)
	goto LOOPEND;
      if(c1==L[i])
	{
	  for(j=i;j<i+M;j++)
	    if(output[j]!=1)
	      output[j]=0;
	}
      else if(c1+cr==L[i] && cr>0)
	{
	  for(j=i;j<i+M;j++)
	    if(output[j]!=0)
		output[j]=1;
	}
      else if(c1+cr < L[i])
	{
	  errno=5;errpos=i;
	  longjmp(jb,1);
	}
      else if(c0+cr < M-L[i])
	{
	  errno=6;errpos=i;
	  longjmp(jb,1);
	}
    LOOPEND:
      ;
    }
}

int count_undef(int output[])
{
  int i,ret;
  for(i=ret=0;i<M+N-1;i++)
    ret += ((output[i]==-1)?1:0);
}

solve()
{
  int i,v,dif,ud1,ud2;

  memset(output,-1,sizeof(output));
  memset(rel   ,-1,sizeof(rel));
  varcnt=0;
  for(i=0;i<N-1;i++)
    {
      dif=L[i]-L[i+1];
      if(dif==1)
	{
	  if(output[i]==1 || output[i]==-1)
	    { 
	      output[i]=1;
	      output[i+M]=0;
	    }
	  else
	    {
	      errno=1;errpos=i;
	      longjmp(jb,1);
	    }
	}
      else if(dif==-1)
	{
	  if(output[i]==0 || output[i]==-1)
	    { 
	      output[i]=0;
	      output[i+M]=1;
	    }
	  else
	    {
	      errno=2;errpos=i;
	      longjmp(jb,1);
	    }
	  }
      else if(dif==0)
	{
	  if(rel[i]==-1)
	    {
	      rel[i]=varcnt;
	      rel[i+M]=varcnt;
	      varcnt++;
	    }
	  else
	    rel[i+M]=rel[i];
	}
      else 
	{
	  errno=3;
	  longjmp(jb,1);
	}
    }
  fill_blank(L,output,rel);
  ud1=count_undef(output);
  do{
    ud2=ud1;
    fill_blank(L,output,rel);
    ud1=count_undef(output);
  }while(ud1!=ud2);
  if(ud1)
    for(i=0;i<N+M-1;i++)
      if(output[i]==-1)
	{
	  output[i]=0;
	  fill_blank(L,output,rel);
	  break;
	}
}

main()
{
  int i,ret;
  while(scanf("%d %d",&N,&M)  && (N||M))
    {
      for(i=0;i<N;i++)
	scanf("%d",&L[i]);

	if(setjmp(jb)==0)
	  {
	    solve();
	    for(i=0;i<M+N-1;i++)
	      printf("%d",output[i]);
	    printf("\n");
	  }
	else
	  {
	    printf("Goofy\n");
	  }
    }
  return(0);
}