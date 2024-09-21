/*
  AOJ 1519
  Title:Room of Time and Spirit
  @kankichi573
  2016/06/16 WA 6/44
*/
#include <stdio.h>
#include <limits.h>

int N,Q;
int offset[100001];
int base[100001];

void training(int a,int b,int c)
{
  int i,d,oldbase;
  
  if(base[a]==0 && base[b]==0)
    {
      offset[a]=c;
      offset[b]=c*2;
      base[a]  = base[b]  =a;
    }
  else if(base[a]==0 && base[b]!=0)
    {
      offset[a]= offset[b];
      base[a]  = base[b];
      offset[b] += c;
    }
  else if(base[a]!=0 && base[b]==0)
    {
	offset[a] += c;
	offset[b] = offset[a]+c;
	base[b]=base[a];
    }
  else if(base[a]!=base[b])
	  {
	    oldbase=base[b];
	    d = offset[a]-offset[b]+c;

	    offset[a] += c;
	    offset[b] = offset[a]+c;
	    base[b]=base[a];


	    for(i=1;i<=N;i++)
	      if(base[i]==oldbase)
		{
		  offset[i] += d;
		  base[i]=a;
		}
	  }
  else
    {
      offset[a] += c;
      offset[b] += c;
    }
}

void query(int a,int b)
{
  if(base[a]!=base[b] || base[a]==0)
    printf("WARNING\n");
  else
    printf("%d\n",offset[b]-offset[a]);
}

void dump()
{
  int i;
  for(i=1;i<=N;i++)
    printf("%2d [%2d]|",offset[i],base[i]);
  printf("\n");
}

main()
{
  int i,a,b,c;
  char order[8];
  
  scanf("%d %d",&N,&Q);
  for(i=0;i<Q;i++)
    {
      scanf("%s %d %d",order,&a,&b);
      if(0==strcmp("IN",order))
	{
	  scanf("%d",&c);
	  training(a,b,c);
	}
      else
	query(a,b);

      dump();
    }
  return(0);
}