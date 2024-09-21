/*
  AOJ 2667
  Title:Tree
  @kankichi573
  2015/9/25 RE
*/
#include <stdio.h>
#include <string.h>
int N,Q;
int parent[150001];
int weight[150001];

int get_common_ancestor(int n1,int n2)
{
  if(n1==n2)
    return(n1);
  else if(n1>n2)
    return get_common_ancestor(parent[n1],n2);
  else
    return get_common_ancestor(n1,parent[n2]);
}

int get_weight_from_root(int node)
{
  int w,c,ret;

  c=ret=0;
  if(node==0)
    return(0);
  do
    {
      node=parent[node];
      //printf("n=%d|",node);
      c++;
      if(w=weight[node])
	ret += c*w;
    }
  while(node>0);
  return(ret);
}

int get_weight_between2(int n1,int n2)
{
  return get_weight_from_root(n1)-get_weight_from_root(n2);
}
int get_weight_between(int n1,int n2)
{
  int n0;
  n0=get_common_ancestor(n1,n2);
  return get_weight_between2(n1,n0)+get_weight_between2(n2,n0);
  //return(0);
}

main()
{
  int i,ret,a,b,c,n;
  
  scanf("%d %d",&N,&Q);
  for(i=0;i<N-1;i++)
    {
      scanf("%d %d",&a,&b);
      parent[b]=a;
    }

  for(i=0;i<Q;i++)
    {
      scanf("%d %d %d",&a,&b,&c);
      if(a==1)
	weight[b] += c;
      else
	{
	  //printf("dist %d,%d|",b,c);
	  ret=get_weight_between(b,c);
	  printf("%d\n",ret);
	}
    }
  
}